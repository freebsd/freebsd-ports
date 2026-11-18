--- components/signin/public/identity_manager/account_capabilities.cc.orig	2026-11-17 21:17:00 UTC
+++ components/signin/public/identity_manager/account_capabilities.cc
@@ -152,7 +152,7 @@ signin::Tribool AccountCapabilities::can_sign_in_to_ch
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 signin::Tribool AccountCapabilities::can_submit_feedback() const {
   return GetCapabilityByName(kCanSubmitFeedbackInChromeCapabilityName);
 }
