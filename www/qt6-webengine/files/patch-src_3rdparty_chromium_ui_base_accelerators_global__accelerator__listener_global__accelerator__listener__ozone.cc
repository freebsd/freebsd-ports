--- src/3rdparty/chromium/ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -12,7 +12,7 @@
 #include "ui/base/accelerators/accelerator.h"
 #include "ui/ozone/public/ozone_platform.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/feature_list.h"
 #include "ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_linux.h"
 #endif
@@ -20,7 +20,7 @@ namespace {
 using content::BrowserThread;
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal,
              "GlobalShortcutsPortal",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -38,7 +38,7 @@ GlobalAcceleratorListener* GlobalAcceleratorListener::
     return instance->get();
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   if (base::FeatureList::IsEnabled(kGlobalShortcutsPortal)) {
     static GlobalAcceleratorListenerLinux* const linux_instance =
         new GlobalAcceleratorListenerLinux(nullptr);
