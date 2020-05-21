--- src/messages/log.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/log.c
@@ -167,7 +167,7 @@ Log_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     submit = message->message;
