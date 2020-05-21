--- src/messages/alert_child.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/alert_child.c
@@ -106,7 +106,7 @@ AlertChild_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg) )
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     alert = message->message;
