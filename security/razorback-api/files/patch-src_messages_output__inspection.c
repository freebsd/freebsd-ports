--- src/messages/output_inspection.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/output_inspection.c
@@ -102,7 +102,7 @@ OutputInspection_Deserialize_Json(struct Message *mess
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     event = message->message;
