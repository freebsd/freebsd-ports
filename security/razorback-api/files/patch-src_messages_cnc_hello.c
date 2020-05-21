--- src/messages/cnc/hello.c.orig	2012-04-19 15:47:21 UTC
+++ src/messages/cnc/hello.c
@@ -121,7 +121,7 @@ Hello_Deserialize_Json(struct Message *message)
     if (message == NULL)
         return false;
 
-    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL || is_error(msg))
+    if ((msg = json_tokener_parse((char *)message->serialized)) == NULL)
         return false;
  
     hello = message->message;
