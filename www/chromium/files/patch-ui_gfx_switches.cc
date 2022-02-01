--- ui/gfx/switches.cc.orig	2022-01-21 13:39:59 UTC
+++ ui/gfx/switches.cc
@@ -26,7 +26,7 @@ const char kForcePrefersReducedMotion[] = "force-prefe
 // Run in headless mode, i.e., without a UI or display server dependencies.
 const char kHeadless[] = "headless";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Which X11 display to connect to. Emulates the GTK+ "--display=" command line
 // argument. In use only with Ozone/X11.
 const char kX11Display[] = "display";
