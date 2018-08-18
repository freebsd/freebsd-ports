--- components/update_client/update_query_params.cc.orig	2017-06-05 19:03:06 UTC
+++ components/update_client/update_query_params.cc
@@ -35,6 +35,8 @@ const char kOs[] =
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
