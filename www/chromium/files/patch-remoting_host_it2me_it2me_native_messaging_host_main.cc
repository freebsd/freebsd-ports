--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2017-08-10 16:26:53.553976000 +0200
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc	2017-08-10 16:27:23.735020000 +0200
@@ -25,7 +25,7 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 #include <X11/Xlib.h>
 
@@ -83,7 +83,7 @@
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
