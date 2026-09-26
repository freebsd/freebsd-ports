--- components/signin/internal/identity_manager/account_capabilities_list.h.orig	2026-09-25 15:26:43 UTC
+++ components/signin/internal/identity_manager/account_capabilities_list.h
@@ -76,7 +76,7 @@ ACCOUNT_CAPABILITY(
     "accountcapabilities/gi2tklldmfya")
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 ACCOUNT_CAPABILITY(kCanSubmitFeedbackInChromeCapabilityName,
                    CAN_SUBMIT_FEEDBACK_IN_CHROME_CAPABILITY_NAME,
                    "accountcapabilities/gizdqmrnmnqxa")
