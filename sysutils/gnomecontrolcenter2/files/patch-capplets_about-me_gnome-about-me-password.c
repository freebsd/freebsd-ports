--- capplets/about-me/gnome-about-me-password.c.orig	Mon Nov 28 10:02:57 2005
+++ capplets/about-me/gnome-about-me-password.c	Wed Dec 14 13:56:42 2005
@@ -25,7 +25,9 @@
 #  include <config.h>
 #endif
 
+#ifndef __FreeBSD__
 #include <stropts.h>
+#endif
 #include <gnome.h>
 #include <pwd.h>
 #include <stdlib.h>
@@ -45,6 +47,12 @@
 
 #if __sun
 #include <sys/types.h>
+#include <signal.h>
+#endif
+
+#if __FreeBSD__
+#include <sys/types.h>
+#include <libutil.h>
 #include <signal.h>
 #endif
 
