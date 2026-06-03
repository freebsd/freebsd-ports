--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2026-05-09 18:09:27 UTC
+++ content/browser/scheduler/responsiveness/native_event_observer.h
@@ -18,7 +18,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/platform/platform_event_observer.h"
 #endif
 
@@ -43,7 +43,7 @@ namespace responsiveness {
 class CONTENT_EXPORT BrowserUINativeEventObserver
 #if BUILDFLAG(IS_MAC)
     : public NativeEventProcessorObserver
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     : public ui::PlatformEventObserver
 #elif BUILDFLAG(IS_WIN)
     : public base::MessagePumpForUI::NativeEventObserver
@@ -60,7 +60,7 @@ class CONTENT_EXPORT BrowserUINativeEventObserver
   BrowserUINativeEventObserver(WillRunEventCallback will_run_event_callback,
                                DidRunEventCallback did_run_event_callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   BrowserUINativeEventObserver(const BrowserUINativeEventObserver&) = delete;
   BrowserUINativeEventObserver& operator=(const BrowserUINativeEventObserver&) =
@@ -72,7 +72,7 @@ class CONTENT_EXPORT BrowserUINativeEventObserver
 #endif
 
  protected:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // ui::PlatformEventObserver overrides:
   void WillProcessEvent(const ui::PlatformEvent& event) override;
   void DidProcessEvent(const ui::PlatformEvent& event) override;
@@ -88,7 +88,7 @@ class CONTENT_EXPORT BrowserUINativeEventObserver
   void RegisterObserver();
   void UnregisterObserver();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct EventInfo {
     uintptr_t unique_id;
   };
