--- src/messages/cnc/reg_req.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/cnc/reg_req.c
@@ -183,7 +183,7 @@ RegistrationRequest_Deserialize_Json(struct Message *m
     if (message == NULL)
         return false;
     
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
  
     regReq = message->message;
