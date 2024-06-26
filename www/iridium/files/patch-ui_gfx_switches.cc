--- ui/gfx/switches.cc.orig	2024-06-25 12:08:48 UTC
+++ ui/gfx/switches.cc
@@ -32,7 +32,7 @@ const char kForcePrefersNoReducedMotion[] = "force-pre
 // Run in headless mode, i.e., without a UI or display server dependencies.
 const char kHeadless[] = "headless";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Which X11 display to connect to. Emulates the GTK+ "--display=" command line
 // argument. In use only with Ozone/X11.
 const char kX11Display[] = "display";
