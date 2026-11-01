--- chrome/browser/ui/toasts/toast_service.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/ui/toasts/toast_service.cc
@@ -143,7 +143,7 @@ void ToastService::RegisterToasts(
                                   IDS_CLEAR_BROWSING_DATA_TOAST_BODY)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   toast_registry_->RegisterToast(
       ToastId::kScheduledRestartOnIdle,
       ToastSpecification::Builder(features::IsRoundedIconsEnabled()
