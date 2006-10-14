--- capplets/about-me/gnome-about-me-password.c.orig	Sun Jun 11 04:50:31 2006
+++ capplets/about-me/gnome-about-me-password.c	Tue Jun 13 00:02:27 2006
@@ -52,6 +52,12 @@
 #include <signal.h>
 #endif
 
+#if __FreeBSD__
+#include <sys/types.h>
+#include <libutil.h>
+#include <signal.h>
+#endif
+
 #include "capplet-util.h"
 #include "eel-alert-dialog.h"
 
