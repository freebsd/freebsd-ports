diff -ur plor-0.3.1/video.c plor-new/video.c
--- plor-0.3.1/video.c	Sat Mar 15 07:15:40 1997
+++ video.c	Thu Jul  3 12:17:24 1997
@@ -8,16 +8,13 @@
  * see file COPYING for more information on copyright policy
  */
 
-#ifdef _HAVE_PARAM_H
 #include <sys/param.h>
-#endif
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <termbits.h>   /* need on a GLIBC system? */
 #if defined(BSD)
 #include <termios.h>
 #endif
