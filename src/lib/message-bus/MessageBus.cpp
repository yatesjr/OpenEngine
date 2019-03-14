//
// Created by jyates on 2/13/19.
//

#include <message-bus/MessageBus.h>

#include "message-bus/MessageBus.h"
#include "message-bus/MessageType.h"

uint32_t MessageBus::registerHandler(UniqueID messageID,
        std::function<void(std::unique_ptr<MessageType>)> handler) {

    // The type should be registered (which is done via the constructor of the
    // subclass).
    auto messageTypeIt = handlerMap.find(messageID);
    if (messageTypeIt != handlerMap.end()) {
        HandlerStore newHandler;
        newHandler.handler = std::move(handler);
        newHandler.identifier = messageTypeIt->second.size();
        messageTypeIt->second.push_back(newHandler);
        return newHandler.identifier;

    } else {
        throw std::runtime_error("message type was not registered");
    }
}

void MessageBus::removeHandler(UniqueID messageID, std::uint32_t handlerIdentifier) {
    auto messageTypeIt = handlerMap.find(messageID);
    if (messageTypeIt != handlerMap.end()) {
        std::vector<HandlerStore>& handlers = messageTypeIt->second;
        if (handlerIdentifier > handlers.size()) {
            for (auto handlerIt: handlers) {
                if (handlerIt.identifier == handlerIdentifier) {

                }
            }
        }
    }
}
