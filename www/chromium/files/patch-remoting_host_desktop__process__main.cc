--- remoting/host/desktop_process_main.cc.orig	2026-11-11 14:44:17 UTC
+++ remoting/host/desktop_process_main.cc
@@ -31,7 +31,7 @@
 #include "remoting/host/desktop_process.h"
 #include "remoting/host/me2me_desktop_environment.h"
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
 #include "remoting/host/linux/thread_bound_x11_event_source.h"
@@ -42,7 +42,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/systemd_user_env_setter.h"
 #endif
 
@@ -56,7 +56,7 @@
 namespace remoting {
 
 int DesktopProcessMain() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto result = SetSystemdUserEnvironment();
   if (!result.has_value()) {
     LOG(ERROR) << "Failed to set systemd user environment: " << result.error();
@@ -67,7 +67,7 @@ int DesktopProcessMain() {
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
@@ -98,7 +98,7 @@ int DesktopProcessMain() {
   // Launch the input thread.
   scoped_refptr<AutoThreadTaskRunner> input_task_runner =
       AutoThread::CreateWithType("Input thread", ui_task_runner,
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
                                  // X11EventSource requires a UI message pump.
                                  base::MessagePumpType::UI);
 #else
@@ -110,7 +110,7 @@ int DesktopProcessMain() {
       AutoThread::CreateWithType("I/O thread", ui_task_runner,
                                  base::MessagePumpType::IO);
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Create an X11EventSource on the main and input threads, so X events on
   // their x11::Connection instances are dispatched.
   ThreadBoundX11EventSource::CreateForCurrentThread();
