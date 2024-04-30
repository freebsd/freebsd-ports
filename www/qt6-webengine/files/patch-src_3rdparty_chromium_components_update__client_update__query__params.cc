--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -42,6 +42,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
