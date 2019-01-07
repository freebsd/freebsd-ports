--- content/browser/scheduler/responsiveness/native_event_observer.h.orig	2018-12-12 22:56:07.000000000 +0100
+++ content/browser/scheduler/responsiveness/native_event_observer.h	2018-12-30 00:51:50.166518000 +0100
@@ -15,7 +15,7 @@
 #include "content/public/browser/native_event_processor_observer_mac.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/window_event_dispatcher_observer.h"
 #endif
 
@@ -40,7 +40,7 @@
 class CONTENT_EXPORT NativeEventObserver
 #if defined(OS_MACOSX)
     : public NativeEventProcessorObserver
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     : public aura::WindowEventDispatcherObserver
 #elif defined(OS_WIN)
     : public base::MessagePumpForUI::Observer
@@ -60,7 +60,7 @@
   NativeEventObserver(WillRunEventCallback will_run_event_callback,
                       DidRunEventCallback did_run_event_callback);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ~NativeEventObserver() override;
 #else
   virtual ~NativeEventObserver();
@@ -73,7 +73,7 @@
   void WillRunNativeEvent(const void* opaque_identifier) override;
   void DidRunNativeEvent(const void* opaque_identifier,
                          base::TimeTicks creation_time) override;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // aura::WindowEventDispatcherObserver overrides:
   void OnWindowEventDispatcherStartedProcessing(
       aura::WindowEventDispatcher* dispatcher,
@@ -90,7 +90,7 @@
   void RegisterObserver();
   void DeregisterObserver();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct EventInfo {
     const void* unique_id;
     base::TimeTicks creation_time;
