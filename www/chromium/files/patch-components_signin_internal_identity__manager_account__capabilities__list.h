--- components/signin/internal/identity_manager/account_capabilities_list.h.orig	2026-10-18 13:29:39 UTC
+++ components/signin/internal/identity_manager/account_capabilities_list.h
@@ -84,7 +84,7 @@ ACCOUNT_CAPABILITY(kCanSignInToChromeCapabilityName,
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 ACCOUNT_CAPABILITY(kCanSubmitFeedbackInChromeCapabilityName,
                    CAN_SUBMIT_FEEDBACK_IN_CHROME_CAPABILITY_NAME,
                    "accountcapabilities/gizdqmrnmnqxa")
