--- remoting/host/desktop_process_main.cc.orig	2026-05-09 18:09:27 UTC
+++ remoting/host/desktop_process_main.cc
@@ -29,7 +29,7 @@
 #include "remoting/host/desktop_process.h"
 #include "remoting/host/me2me_desktop_environment.h"
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
 #include "ui/gfx/x/xlib_support.h"
@@ -39,7 +39,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/systemd_user_env_setter.h"
 #endif
 
@@ -54,7 +54,7 @@
 namespace remoting {
 
 int DesktopProcessMain() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto result = SetSystemdUserEnvironment();
   if (!result.has_value()) {
     LOG(ERROR) << "Failed to set systemd user environment: " << result.error();
@@ -65,7 +65,7 @@ int DesktopProcessMain() {
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
