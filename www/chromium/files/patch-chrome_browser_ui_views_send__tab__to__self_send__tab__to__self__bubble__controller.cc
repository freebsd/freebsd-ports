--- chrome/browser/ui/views/send_tab_to_self/send_tab_to_self_bubble_controller.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/send_tab_to_self/send_tab_to_self_bubble_controller.cc
@@ -44,7 +44,7 @@
 #include "ui/events/event.h"
 #include "ui/views/bubble/bubble_dialog_delegate_view.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/signin/cross_device_signin_promo_manager.h"
 #include "chrome/browser/signin/signin_util.h"
 #include "components/signin/public/base/signin_switches.h"
@@ -94,7 +94,7 @@ void SendTabToSelfBubbleController::ShowBubbleImpl(
       GlobalBrowserCollection::GetInstance()->FindBrowserWithTab(
           &GetWebContents());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ShouldShowNoTargetDeviceQrBubble(reason, browser)) {
     // Note: `entry_point_` should always be populated here, since it's set in
     // ShowBubble() which must've been called earlier. If it's not (e.g. in some
@@ -311,7 +311,7 @@ void SendTabToSelfBubbleController::OnWidgetDestroying
 bool SendTabToSelfBubbleController::ShouldShowNoTargetDeviceQrBubble(
     EntryPointDisplayReason reason,
     BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (reason != EntryPointDisplayReason::kInformNoTargetDevice || !browser ||
       !base::FeatureList::IsEnabled(switches::kCrossDeviceSigninFromDesktop) ||
       !base::FeatureList::IsEnabled(
