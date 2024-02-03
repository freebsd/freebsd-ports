--- chrome/browser/ui/webui/settings/accessibility_main_handler.h.orig	2024-02-03 15:42:55 UTC
+++ chrome/browser/ui/webui/settings/accessibility_main_handler.h
@@ -13,7 +13,7 @@
 #include "chrome/browser/ash/accessibility/accessibility_manager.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/screen_ai/screen_ai_install_state.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -24,7 +24,7 @@ namespace settings {
 // chrome://settings/accessibility.
 class AccessibilityMainHandler
     : public ::settings::SettingsPageUIHandler
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     ,
       public screen_ai::ScreenAIInstallState::Observer
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -40,7 +40,7 @@ class AccessibilityMainHandler
   void OnJavascriptAllowed() override;
   void OnJavascriptDisallowed() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // screen_ai::ScreenAIInstallState::Observer:
   void DownloadProgressChanged(double progress) override;
   void StateChanged(screen_ai::ScreenAIInstallState::State state) override;
@@ -59,7 +59,7 @@ class AccessibilityMainHandler
   base::CallbackListSubscription accessibility_subscription_;
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<screen_ai::ScreenAIInstallState,
                           screen_ai::ScreenAIInstallState::Observer>
       component_ready_observer_{this};
