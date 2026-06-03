--- components/translate/core/common/translate_util.cc.orig	2026-03-13 06:02:14 UTC
+++ components/translate/core/common/translate_util.cc
@@ -44,7 +44,7 @@ bool IsTFLiteLanguageDetectionEnabled() {
 // The feature is explicitly disabled on WebView.
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
