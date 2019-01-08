--- content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2018-12-12 22:56:07.000000000 +0100
+++ content/browser/scheduler/responsiveness/native_event_observer.cc	2018-12-29 17:27:50.449973000 +0100
@@ -17,7 +17,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/env.h"
 #include "ui/events/event.h"
 #endif
@@ -29,7 +29,7 @@
 namespace content {
 namespace responsiveness {
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && defined(USE_X11))
+#if defined(OS_WIN) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11))
 
 namespace {
 
@@ -64,7 +64,7 @@
   DeregisterObserver();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeEventObserver::RegisterObserver() {
   aura::Env::GetInstance()->AddWindowEventDispatcherObserver(this);
 }
