--- content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2019-01-30 02:17:59.000000000 +0100
+++ content/browser/scheduler/responsiveness/native_event_observer.cc	2019-02-01 00:19:02.237926000 +0100
@@ -15,7 +15,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/env.h"
 #include "ui/events/event.h"
 #endif
@@ -39,7 +39,7 @@
   DeregisterObserver();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeEventObserver::RegisterObserver() {
   aura::Env::GetInstance()->AddWindowEventDispatcherObserver(this);
 }
@@ -61,7 +61,7 @@
   did_run_event_callback_.Run(info.unique_id);
   events_being_processed_.pop_back();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 void NativeEventObserver::RegisterObserver() {
