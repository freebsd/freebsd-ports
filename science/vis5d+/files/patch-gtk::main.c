--- gtk/main.c.orig	Wed Jan  9 13:08:24 2002
+++ gtk/main.c	Wed Jan  9 13:08:34 2002
@@ -8,7 +8,6 @@
 #endif
 #include <gtk/gtk.h>
 
-#include <mcheck.h>
 #include <signal.h>
 
 #include "window3D.h"
@@ -18,14 +17,12 @@
 static void
 enable (int sig)
 {
-  mtrace ();
   signal (SIGUSR1, enable);
 }
 
 static void
 disable (int sig)
 {
-  muntrace ();
   signal (SIGUSR2, disable);
 }
 
