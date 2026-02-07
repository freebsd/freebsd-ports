--- components/translate/core/common/translate_util.cc.orig	2025-10-30 15:44:36 UTC
+++ components/translate/core/common/translate_util.cc
@@ -19,7 +19,7 @@ const char kSecurityOrigin[] = "https://translate.goog
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
