--- src/chrome/browser/ui/toasts/toast_service.cc.orig	2026-10-20 12:27:58 UTC
+++ src/chrome/browser/ui/toasts/toast_service.cc
@@ -152,7 +152,7 @@ void ToastService::RegisterToasts(
                                   IDS_CLEAR_BROWSING_DATA_TOAST_BODY)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   toast_registry_->RegisterToast(
       ToastId::kScheduledRestartOnIdle,
       ToastSpecification::Builder(features::IsRoundedIconsEnabled()
