--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2021-09-14 01:51:56 UTC
+++ content/browser/scheduler/responsiveness/native_event_observer.h
@@ -16,7 +16,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/aura/window_event_dispatcher_observer.h"
 #endif
 
@@ -41,7 +41,7 @@ namespace responsiveness {
 class CONTENT_EXPORT NativeEventObserver
 #if defined(OS_MAC)
     : public NativeEventProcessorObserver
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     : public aura::WindowEventDispatcherObserver
 #elif defined(OS_WIN)
     : public base::MessagePumpForUI::Observer
@@ -58,7 +58,7 @@ class CONTENT_EXPORT NativeEventObserver
   NativeEventObserver(WillRunEventCallback will_run_event_callback,
                       DidRunEventCallback did_run_event_callback);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ~NativeEventObserver() override;
 #else
   virtual ~NativeEventObserver();
@@ -70,7 +70,7 @@ class CONTENT_EXPORT NativeEventObserver
   // Exposed for tests.
   void WillRunNativeEvent(const void* opaque_identifier) override;
   void DidRunNativeEvent(const void* opaque_identifier) override;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // aura::WindowEventDispatcherObserver overrides:
   void OnWindowEventDispatcherStartedProcessing(
       aura::WindowEventDispatcher* dispatcher,
@@ -87,7 +87,7 @@ class CONTENT_EXPORT NativeEventObserver
   void RegisterObserver();
   void DeregisterObserver();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct EventInfo {
     const void* unique_id;
   };
