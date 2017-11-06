--- components/update_client/update_query_params.cc.orig	2017-04-19 19:06:33 UTC
+++ components/update_client/update_query_params.cc
@@ -34,6 +34,8 @@ const char kOs[] =
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
