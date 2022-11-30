--- src/text_anonymizer.cc.orig	2022-11-30 03:22:52 UTC
+++ src/text_anonymizer.cc
@@ -31,6 +31,7 @@
 
 #include <arpa/inet.h>
 #include <curl/curl.h>
+#include <netinet/in.h>
 
 #include "animals-json.h"
 #include "config.h"
