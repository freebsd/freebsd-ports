--- src/utmplib.c.orig	Mon Jan 20 11:42:57 2003
+++ src/utmplib.c	Mon Jan 20 11:43:05 2003
@@ -32,6 +32,7 @@
 
 #if !defined(HAVE_SETUTENT) && !defined (HAVE_UTMPX_H)
 
+#include <sys/types.h>
 #include <time.h> /* Don't ask... */
 #include <utmp.h>
 #include <fcntl.h>
