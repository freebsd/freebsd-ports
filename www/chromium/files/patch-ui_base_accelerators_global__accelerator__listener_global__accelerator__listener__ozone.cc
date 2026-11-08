--- ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2026-09-25 15:26:43 UTC
+++ ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS)
 #include "ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_chromeos.h"
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/environment.h"
 #include "base/feature_list.h"
 #include "base/nix/xdg_util.h"
@@ -23,7 +23,7 @@
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal, base::FEATURE_ENABLED_BY_DEFAULT);
 
 constexpr char kSessionSuffix[] = "_global_shortcuts";
@@ -51,7 +51,7 @@ GlobalAcceleratorListener* GlobalAcceleratorListener::
   static const base::NoDestructor<std::unique_ptr<GlobalAcceleratorListener>>
       chromeos_instance(GlobalAcceleratorListenerChromeOS::Create());
   return chromeos_instance->get();
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   // ListShortcuts on GNOME will return an empty list when the session is
   // created, making this class incorrectly believe it must rebind all
   // shortcuts, leading to a dialog shown on every browser start.
