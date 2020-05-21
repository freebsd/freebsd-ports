--- src/messages/judgment.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/judgment.c
@@ -119,7 +119,7 @@ JudgmentSubmission_Deserialize_Json(struct Message *me
     if (message == NULL)
         return false;
     
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
     
     submit = message->message;
