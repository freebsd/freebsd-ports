--- kadu-core/gui/widgets/chat-widget/chat-widget-impl.cpp.orig	2016-10-19 17:23:42 UTC
+++ kadu-core/gui/widgets/chat-widget/chat-widget-impl.cpp
@@ -720,7 +720,7 @@ void ChatWidgetImpl::contactActivityChan
 
 	if (CurrentContactActivity == ChatState::Gone)
 	{
-		auto msg = QString{"[ " + tr("%1 ended the conversation").arg(contact.ownerBuddy().display()) + " ]"};
+		auto msg = QString("[ " + tr("%1 ended the conversation").arg(contact.ownerBuddy().display()) + " ]");
 		Message message = m_messageStorage->create();
 		message.setMessageChat(CurrentChat);
 		message.setType(MessageTypeSystem);
