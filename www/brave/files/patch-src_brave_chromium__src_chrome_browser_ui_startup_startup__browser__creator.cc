--- src/brave/chromium_src/chrome/browser/ui/startup/startup_browser_creator.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/startup/startup_browser_creator.cc
@@ -23,7 +23,7 @@
 #include "chrome/browser/platform_util.h"
 #include "chrome/browser/profiles/profile_manager.h"
 #include "components/prefs/pref_service.h"
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -136,7 +136,7 @@
         std::move(callback));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // Provide the WM_CLASS name/class so the Linux window manager can match this
   // window to the Brave .desktop file and display the correct taskbar icon
   // instead of a generic one.
