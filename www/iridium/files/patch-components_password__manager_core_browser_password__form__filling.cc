--- components/password_manager/core/browser/password_form_filling.cc.orig	2026-08-13 16:48:13 UTC
+++ components/password_manager/core/browser/password_form_filling.cc
@@ -178,7 +178,7 @@ LikelyFormFilling SendFillInformationToRenderer(
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!should_show_popup_without_passwords) {
       url::Origin origin =
           base::FeatureList::IsEnabled(
