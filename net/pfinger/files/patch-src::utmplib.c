--- src/utmplib.c.orig	Tue Nov 27 01:52:39 2001
+++ src/utmplib.c	Tue Nov 27 01:53:08 2001
@@ -32,6 +32,7 @@
 
 #if !defined(HAVE_SETUTENT) && !defined (HAVE_UTMPX_H)
 
+#include <sys/types.h>
 #include <syslog.h>
 #include <time.h> /* Don't ask... */
 #include <utmp.h>
