--- remoting/host/me2me_desktop_environment.cc.orig	2017-08-10 16:28:52.379518000 +0200
+++ remoting/host/me2me_desktop_environment.cc	2017-08-10 16:29:10.165289000 +0200
@@ -99,7 +99,7 @@
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool want_user_interface = false;
 #elif defined(OS_MACOSX)
   // Don't try to display any UI on top of the system's login screen as this
