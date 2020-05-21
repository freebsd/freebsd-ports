--- src/messages/inspection.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/inspection.c
@@ -192,7 +192,7 @@ InspectionSubmission_Deserialize_Json(struct Message *
     if (message == NULL)
         return false;
     
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     submit = message->message;
