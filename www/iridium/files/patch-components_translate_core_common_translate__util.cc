--- components/translate/core/common/translate_util.cc.orig	2026-02-16 10:45:29 UTC
+++ components/translate/core/common/translate_util.cc
@@ -29,7 +29,7 @@ bool IsTFLiteLanguageDetectionEnabled() {
 // The feature is explicitly disabled on WebView.
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
