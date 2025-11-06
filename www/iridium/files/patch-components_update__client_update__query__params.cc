--- components/update_client/update_query_params.cc.orig	2025-11-06 10:11:34 UTC
+++ components/update_client/update_query_params.cc
@@ -39,6 +39,8 @@ constexpr std::string_view kOs =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
