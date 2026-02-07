--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -39,6 +39,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
