--- src/connection.c.orig	Fri Jan 26 02:16:40 2007
+++ src/connection.c	Fri Jan 26 02:17:25 2007
@@ -14,10 +14,11 @@
 
 RapiConnection* rapi_connection_from_path(const char* path)
 {
+  RapiConnection* result;
   SynceInfo* info = synce_info_new(path);
   if (info == NULL)
     return NULL;
-  RapiConnection* result = rapi_connection_from_info(info);
+  result = rapi_connection_from_info(info);
   if (result)
     result->owned_info = info;
 
