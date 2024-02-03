--- components/qr_code_generator/features.cc.orig	2024-02-03 15:42:55 UTC
+++ components/qr_code_generator/features.cc
@@ -12,7 +12,7 @@ namespace qr_code_generator {
 BASE_FEATURE(kRustyQrCodeGeneratorFeature,
              "RustyQrCodeGenerator",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
