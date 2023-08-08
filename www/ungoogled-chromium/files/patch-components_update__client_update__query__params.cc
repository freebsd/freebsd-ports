--- components/update_client/update_query_params.cc.orig	2023-07-21 09:49:17 UTC
+++ components/update_client/update_query_params.cc
@@ -42,6 +42,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
