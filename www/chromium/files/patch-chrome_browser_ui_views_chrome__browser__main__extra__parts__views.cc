--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -36,7 +36,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -131,7 +131,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
         return controller;
       }));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
