--- services/network/public/cpp/features.cc.orig	2025-10-21 16:57:35 UTC
+++ services/network/public/cpp/features.cc
@@ -396,7 +396,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies,
 BASE_FEATURE(kDocumentIsolationPolicy,
              "DocumentIsolationPolicy",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
