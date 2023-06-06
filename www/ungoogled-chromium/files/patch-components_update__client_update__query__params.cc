--- components/update_client/update_query_params.cc.orig	2023-06-05 19:39:05 UTC
+++ components/update_client/update_query_params.cc
@@ -41,6 +41,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
