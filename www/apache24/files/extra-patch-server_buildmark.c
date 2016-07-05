# disable build time stamp in favor of reproducible build
# except building with DEBUG
==============================================================
--- server/buildmark.c.orig	2016-07-03 16:09:18 UTC
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
