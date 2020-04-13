--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -38,6 +38,8 @@ const char kOs[] =
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
