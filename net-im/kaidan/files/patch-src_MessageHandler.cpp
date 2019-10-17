The interface expected here is not yet present in the release 

--- src/MessageHandler.cpp.orig	2019-10-17 07:52:52 UTC
+++ src/MessageHandler.cpp
@@ -101,7 +101,7 @@ void MessageHandler::handleMessage(const QXmppMessage 
 	message.setId(msg.id());
 	message.setBody(msg.body());
 	message.setMediaType(MessageType::MessageText); // default to text message without media
-#if (QXMPP_VERSION) >= QT_VERSION_CHECK(1, 0, 1)
+#if 0
 	message.setIsSpoiler(msg.isSpoiler());
 	message.setSpoilerHint(msg.spoilerHint());
 #else
