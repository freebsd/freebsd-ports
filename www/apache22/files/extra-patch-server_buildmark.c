--- server/buildmark.c.orig	2017-06-09 18:42:01 UTC
+++ server/buildmark.c
@@ -17,6 +17,9 @@
 #include "ap_config.h"
 #include "httpd.h"
 
+/* Allow Reproducible build, do not include build time information */
+#undef __DATE__
+
 #if defined(__DATE__) && defined(__TIME__)
 static const char server_built[] = __DATE__ " " __TIME__;
 #else
