--- src/messages/output_event.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/output_event.c
@@ -89,7 +89,7 @@ OutputEvent_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     event = message->message;
