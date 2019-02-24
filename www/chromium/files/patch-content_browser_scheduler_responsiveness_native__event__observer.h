--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2019-01-30 02:17:59.000000000 +0100
+++ content/browser/scheduler/responsiveness/native_event_observer.h	2019-02-01 00:24:39.349687000 +0100
@@ -14,7 +14,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/window_event_dispatcher_observer.h"
 #endif
 
@@ -39,7 +39,7 @@
 class CONTENT_EXPORT NativeEventObserver
 #if defined(OS_MACOSX)
     : public NativeEventProcessorObserver
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     : public aura::WindowEventDispatcherObserver
 #elif defined(OS_WIN)
     : public base::MessagePumpForUI::Observer
@@ -56,7 +56,7 @@
   NativeEventObserver(WillRunEventCallback will_run_event_callback,
                       DidRunEventCallback did_run_event_callback);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ~NativeEventObserver() override;
 #else
   virtual ~NativeEventObserver();
@@ -68,7 +68,7 @@
   // Exposed for tests.
   void WillRunNativeEvent(const void* opaque_identifier) override;
   void DidRunNativeEvent(const void* opaque_identifier) override;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // aura::WindowEventDispatcherObserver overrides:
   void OnWindowEventDispatcherStartedProcessing(
       aura::WindowEventDispatcher* dispatcher,
@@ -85,7 +85,7 @@
   void RegisterObserver();
   void DeregisterObserver();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct EventInfo {
     const void* unique_id;
   };
