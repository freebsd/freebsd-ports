--- src/xt_control.c.orig	Sat Feb 14 21:48:14 2004
+++ src/xt_control.c	Sun Apr 25 10:56:23 2004
@@ -29,6 +29,9 @@
 #include <stdlib.h>
 #include <limits.h>		/* PATH_MAX */
 #include <ctype.h>		/* isdigit() */
+#ifdef HAVE_SYS_TIME_H
+# include <sys/time.h>
+#endif
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <X11/Shell.h>
