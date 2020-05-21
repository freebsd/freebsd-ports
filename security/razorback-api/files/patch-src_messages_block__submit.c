--- src/messages/block_submit.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/block_submit.c
@@ -127,7 +127,7 @@ BlockSubmission_Deserialize_Json(struct Message *messa
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
 
     submit = message->message;
