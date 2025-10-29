--- components/translate/core/common/translate_util.cc.orig	2025-10-28 14:29:43 UTC
+++ components/translate/core/common/translate_util.cc
@@ -20,7 +20,7 @@ const char kSecurityOrigin[] = "trk:220:https://transl
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
              "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
