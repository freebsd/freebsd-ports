--- gnome-im-switcher/src/widgets.c	Thu Oct 14 23:10:11 2004
+++ gnome-im-switcher/src/widgets.c	Wed Feb 16 16:51:26 2005
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
