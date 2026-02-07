--- components/translate/core/common/translate_util.cc.orig	2025-11-01 06:40:37 UTC
+++ components/translate/core/common/translate_util.cc
@@ -19,7 +19,7 @@ const char kSecurityOrigin[] = "trk:220:https://transl
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
