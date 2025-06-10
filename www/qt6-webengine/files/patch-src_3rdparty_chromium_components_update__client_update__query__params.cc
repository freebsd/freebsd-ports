--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -40,6 +40,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
