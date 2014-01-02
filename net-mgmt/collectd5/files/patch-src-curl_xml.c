--- src/curl_xml.c.orig	2013-08-18 14:24:25.069973000 +0400
+++ src/curl_xml.c	2014-01-03 00:25:17.000000000 +0400
@@ -607,7 +607,7 @@
   int status;
   long rc;
   char *ptr;
-  char *url;
+  char *url = NULL;
 
   db->buffer_fill = 0; 
   status = curl_easy_perform (curl);
