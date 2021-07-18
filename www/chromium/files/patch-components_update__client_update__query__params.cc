--- components/update_client/update_query_params.cc.orig	2021-04-14 18:41:02 UTC
+++ components/update_client/update_query_params.cc
@@ -40,6 +40,8 @@ const char kOs[] =
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
