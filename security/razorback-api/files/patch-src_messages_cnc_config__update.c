--- src/messages/cnc/config_update.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/cnc/config_update.c
@@ -137,7 +137,7 @@ ConfigUpdate_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
     
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     configUpdate = message->message;
