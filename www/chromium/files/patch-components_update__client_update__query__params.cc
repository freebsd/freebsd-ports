--- components/update_client/update_query_params.cc.orig	2016-05-11 19:02:20 UTC
+++ components/update_client/update_query_params.cc
@@ -31,6 +31,8 @@ const char kOs[] =
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
