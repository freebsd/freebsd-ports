--- src/3rdparty/chromium/content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/browser/scheduler/responsiveness/native_event_observer.cc
@@ -15,7 +15,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/env.h"
 #include "ui/events/event.h"
 #endif
@@ -39,7 +39,7 @@ NativeEventObserver::~NativeEventObserver() {
   DeregisterObserver();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeEventObserver::RegisterObserver() {
   aura::Env::GetInstance()->AddWindowEventDispatcherObserver(this);
 }
@@ -61,7 +61,7 @@ void NativeEventObserver::OnWindowEventDispatcherFinis
   did_run_event_callback_.Run(info.unique_id);
   events_being_processed_.pop_back();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 void NativeEventObserver::RegisterObserver() {
