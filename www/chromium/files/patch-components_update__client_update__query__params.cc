--- components/update_client/update_query_params.cc.orig	2025-02-19 07:43:18 UTC
+++ components/update_client/update_query_params.cc
@@ -39,6 +39,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
