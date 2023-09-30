--- console/fbtools.c.orig	2020-05-15 23:32:25 UTC
+++ console/fbtools.c
@@ -2,6 +2,7 @@
  * some generic framebuffer device stuff
  *
  */
+#ifdef WITH_LINUX_FB_H
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -523,3 +524,4 @@ fb_catch_exit_signals(void)
     fprintf(stderr,"Oops: %s\n",sys_siglist[termsig]);
     exit(42);
 }
+#endif
