--- milter-greylist.c.orig	Sat Nov 27 15:43:17 2004
+++ milter-greylist.c	Sat Dec 11 14:17:14 2004
@@ -56,10 +56,6 @@
 #endif
 #include <sysexits.h>
 
-#if HAVE_GETOPT_H
-#include <getopt.h>
-#endif
-
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/stat.h>
