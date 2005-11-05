--- capplets/about-me/gnome-about-me-password.c.orig	Wed Aug 10 05:45:08 2005
+++ capplets/about-me/gnome-about-me-password.c	Wed Aug 10 15:44:57 2005
@@ -35,7 +35,13 @@
 #include <sys/wait.h>
 #include <sys/poll.h>
 #include <termios.h>
+#include <signal.h>
+#ifndef __FreeBSD__
 #include <pty.h>
+#else
+#include <sys/types.h>
+#include <libutil.h>
+#endif
 
 #include "capplet-util.h"
 #include "eel-alert-dialog.h"
