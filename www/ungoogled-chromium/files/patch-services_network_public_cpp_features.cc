--- services/network/public/cpp/features.cc.orig	2026-02-15 10:01:45 UTC
+++ services/network/public/cpp/features.cc
@@ -369,7 +369,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies, base::FEATUR
 // https://github.com/WICG/document-isolation-policy
 BASE_FEATURE(kDocumentIsolationPolicy,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
