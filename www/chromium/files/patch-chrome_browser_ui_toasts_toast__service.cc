--- chrome/browser/ui/toasts/toast_service.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/toasts/toast_service.cc
@@ -142,7 +142,7 @@ void ToastService::RegisterToasts() {
                                   IDS_CLEAR_BROWSING_DATA_TOAST_BODY)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   toast_registry_->RegisterToast(
       ToastId::kScheduledRestartOnIdle,
       ToastSpecification::Builder(features::IsRoundedIconsEnabled()
