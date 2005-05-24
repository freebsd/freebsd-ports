--- gnome-im-switcher/src/widgets.c.orig	Tue May 10 16:29:36 2005
+++ gnome-im-switcher/src/widgets.c	Tue May 10 16:30:04 2005
@@ -29,7 +29,11 @@
 #include <gnome.h>
 
 #include <signal.h>
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 
 #include "gnome-im-switcher.h"
 #include "iiim-interface.h"
