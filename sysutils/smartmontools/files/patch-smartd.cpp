--- smartd.cpp.orig	2026-02-17 17:19:34 UTC
+++ smartd.cpp
@@ -97,7 +97,7 @@ extern "C" {
   typedef void (*signal_handler_type)(int);
 }
 
-static void set_signal_if_not_ignored(int sig, signal_handler_type handler)
+static void set_signal(int sig, signal_handler_type handler)
 {
 #if defined(_WIN32)
   // signal() emulation
@@ -105,13 +105,7 @@ static void set_signal_if_not_ignored(int sig, signal_
 
 #else
   // SVr4, POSIX.1-2001, ..., POSIX.1-2024
-  struct sigaction sa;
-  sa.sa_handler = SIG_DFL;
-  sigaction(sig, (struct sigaction *)0, &sa);
-  if (sa.sa_handler == SIG_IGN)
-    return;
-
-  sa = {};
+  struct sigaction sa = {};
   sa.sa_handler = handler;
   sa.sa_flags = SA_RESTART; // BSD signal() semantics
   sigaction(sig, &sa, (struct sigaction *)0);
@@ -4401,17 +4395,17 @@ static void CheckDevicesOnce(const dev_config_vector &
 static void install_signal_handlers()
 {
   // normal and abnormal exit
-  set_signal_if_not_ignored(SIGTERM, sighandler);
-  set_signal_if_not_ignored(SIGQUIT, sighandler);
+  set_signal(SIGTERM, sighandler);
+  set_signal(SIGQUIT, sighandler);
   
   // in debug mode, <CONTROL-C> ==> HUP
-  set_signal_if_not_ignored(SIGINT, (debugmode ? HUPhandler : sighandler));
+  set_signal(SIGINT, (debugmode ? HUPhandler : sighandler));
   
   // Catch HUP and USR1
-  set_signal_if_not_ignored(SIGHUP, HUPhandler);
-  set_signal_if_not_ignored(SIGUSR1, USR1handler);
+  set_signal(SIGHUP, HUPhandler);
+  set_signal(SIGUSR1, USR1handler);
 #ifdef _WIN32
-  set_signal_if_not_ignored(SIGUSR2, USR2handler);
+  set_signal(SIGUSR2, USR2handler);
 #endif
 }
 
