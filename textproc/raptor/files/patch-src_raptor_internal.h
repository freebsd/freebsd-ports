--- src/raptor_internal.h.orig	2012-03-05 11:43:28.000000000 +0100
+++ src/raptor_internal.h	2012-03-05 11:43:35.000000000 +0100
@@ -852,7 +852,6 @@
 
 #ifdef RAPTOR_WWW_LIBCURL
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
