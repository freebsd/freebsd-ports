--- services/network/public/cpp/features.cc.orig	2025-05-31 17:16:41 UTC
+++ services/network/public/cpp/features.cc
@@ -380,7 +380,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies,
 BASE_FEATURE(kDocumentIsolationPolicy,
              "DocumentIsolationPolicy",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
