--- src/virustotal.c.orig	2012-03-02 14:05:41 UTC
+++ src/virustotal.c
@@ -5,7 +5,7 @@
 #include <time.h>
 #include <curl/curl.h>
 #include <curl/easy.h>
-#include <json/json.h>
+#include <json-c/json.h>
 #include <arpa/inet.h>
 
 #include <razorback/config_file.h>
