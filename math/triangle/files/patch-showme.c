--- ./showme.c.orig	Wed Apr 28 05:13:34 2004
+++ ./showme.c	Sat Oct 16 23:00:09 2004
@@ -106,6 +106,8 @@
 #include <X11/Xutil.h>
 #include <X11/Xatom.h>
 
+#include <stdlib.h>
+
 /* The following obscenity seems to be necessary to ensure that this program */
 /* will port to Dec Alphas running OSF/1, because their stdio.h file commits */
 /* the unpardonable sin of including stdlib.h.  Hence, malloc(), free(), and */
