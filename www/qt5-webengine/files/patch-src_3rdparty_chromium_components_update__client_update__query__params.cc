--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -39,6 +39,8 @@ const char kOs[] =
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
