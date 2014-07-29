--- console/fbtools.c.orig	Tue Feb 10 22:40:55 2004
+++ console/fbtools.c	Tue Feb 10 22:42:03 2004
@@ -2,6 +2,7 @@
  * some generic framebuffer device stuff
  *
  */
+#ifdef WITH_LINUX_FB_H
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -521,3 +522,4 @@
     fprintf(stderr,"Oops: %s\n",sys_siglist[termsig]);
     exit(42);
 }
+#endif
