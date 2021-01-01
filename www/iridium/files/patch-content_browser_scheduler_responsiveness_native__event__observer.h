--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2019-03-11 22:00:58 UTC
+++ content/browser/scheduler/responsiveness/native_event_observer.h
@@ -14,7 +14,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/window_event_dispatcher_observer.h"
 #endif
 
@@ -39,7 +39,7 @@ namespace responsiveness {
 class CONTENT_EXPORT NativeEventObserver
 #if defined(OS_MACOSX)
     : public NativeEventProcessorObserver
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     : public aura::WindowEventDispatcherObserver
 #elif defined(OS_WIN)
     : public base::MessagePumpForUI::Observer
@@ -56,7 +56,7 @@ class CONTENT_EXPORT NativeEventObserver
   NativeEventObserver(WillRunEventCallback will_run_event_callback,
                       DidRunEventCallback did_run_event_callback);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ~NativeEventObserver() override;
 #else
   virtual ~NativeEventObserver();
@@ -68,7 +68,7 @@ class CONTENT_EXPORT NativeEventObserver
   // Exposed for tests.
   void WillRunNativeEvent(const void* opaque_identifier) override;
   void DidRunNativeEvent(const void* opaque_identifier) override;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // aura::WindowEventDispatcherObserver overrides:
   void OnWindowEventDispatcherStartedProcessing(
       aura::WindowEventDispatcher* dispatcher,
@@ -85,7 +85,7 @@ class CONTENT_EXPORT NativeEventObserver
   void RegisterObserver();
   void DeregisterObserver();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct EventInfo {
     const void* unique_id;
   };
