--- content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2026-02-16 10:45:29 UTC
+++ content/browser/scheduler/responsiveness/native_event_observer.cc
@@ -15,7 +15,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/platform/platform_event_source.h"
 #endif
 
@@ -38,7 +38,7 @@ NativeEventObserver::~NativeEventObserver() {
   DeregisterObserver();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NativeEventObserver::RegisterObserver() {
   CHECK(ui::PlatformEventSource::GetInstance());
   ui::PlatformEventSource::GetInstance()->AddPlatformEventObserver(this);
