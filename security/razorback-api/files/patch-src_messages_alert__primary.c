--- src/messages/alert_primary.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/alert_primary.c
@@ -126,7 +126,7 @@ AlertPrimary_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     alert = message->message;
