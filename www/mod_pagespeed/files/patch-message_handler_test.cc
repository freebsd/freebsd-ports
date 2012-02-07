--- net/instaweb/util/message_handler_test.cc.orig	2012-02-06 15:07:57.961341517 -0500
+++ net/instaweb/util/message_handler_test.cc	2012-02-06 15:08:13.049343814 -0500
@@ -74,7 +74,7 @@
   ASSERT_EQ(messages()[1], "Info: filename.cc: 1: here is another message");
   ASSERT_EQ(kWarning, MessageHandler::StringToMessageType("Warning"));
   ASSERT_EQ(kFatal, MessageHandler::StringToMessageType("Fatal"));
-  ASSERT_DEATH(MessageHandler::StringToMessageType("Random"),
+  ASSERT_DEATH_IF_SUPPORTED(MessageHandler::StringToMessageType("Random"),
                "Invalid msg level: Random");
 }
 
