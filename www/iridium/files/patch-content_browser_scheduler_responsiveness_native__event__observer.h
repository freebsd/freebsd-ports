--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2026-02-16 10:45:29 UTC
+++ content/browser/scheduler/responsiveness/native_event_observer.h
@@ -16,7 +16,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/platform/platform_event_observer.h"
 #endif
 
@@ -41,7 +41,7 @@ namespace responsiveness {
 class CONTENT_EXPORT NativeEventObserver
 #if BUILDFLAG(IS_MAC)
     : public NativeEventProcessorObserver
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     : public ui::PlatformEventObserver
 #elif BUILDFLAG(IS_WIN)
     : public base::MessagePumpForUI::Observer
@@ -58,7 +58,7 @@ class CONTENT_EXPORT NativeEventObserver
   NativeEventObserver(WillRunEventCallback will_run_event_callback,
                       DidRunEventCallback did_run_event_callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   NativeEventObserver(const NativeEventObserver&) = delete;
   NativeEventObserver& operator=(const NativeEventObserver&) = delete;
@@ -74,7 +74,7 @@ class CONTENT_EXPORT NativeEventObserver
   // Exposed for tests.
   void WillRunNativeEvent(const void* opaque_identifier) override;
   void DidRunNativeEvent(const void* opaque_identifier) override;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // ui::PlatformEventObserver overrides:
   void WillProcessEvent(const ui::PlatformEvent& event) override;
   void DidProcessEvent(const ui::PlatformEvent& event) override;
@@ -89,7 +89,7 @@ class CONTENT_EXPORT NativeEventObserver
   void RegisterObserver();
   void DeregisterObserver();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct EventInfo {
     raw_ptr<const void> unique_id;
   };
