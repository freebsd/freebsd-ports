--- src/util.c.orig	Thu May  9 01:16:48 2002
+++ src/util.c	Thu May  9 01:17:13 2002
@@ -16,6 +16,7 @@
 
 #ifdef __FreeBSD__
 # include <errno.h>
+# include <termios.h>
 # include <libutil.h>
 #endif
 
