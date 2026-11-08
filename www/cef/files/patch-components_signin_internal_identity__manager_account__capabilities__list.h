--- components/signin/internal/identity_manager/account_capabilities_list.h.orig	2026-07-01 06:24:19 UTC
+++ components/signin/internal/identity_manager/account_capabilities_list.h
@@ -72,7 +72,7 @@ ACCOUNT_CAPABILITY(
     "accountcapabilities/gi2tklldmfya")
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 ACCOUNT_CAPABILITY(kCanSubmitFeedbackInChromeCapabilityName,
                    CAN_SUBMIT_FEEDBACK_IN_CHROME_CAPABILITY_NAME,
                    "accountcapabilities/gizdqmrnmnqxa")
