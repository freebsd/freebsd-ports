--- metamail/putenv.c.orig	Tue Oct 12 17:17:43 1993
+++ metamail/putenv.c	Mon Dec 18 11:46:22 2006
@@ -17,6 +17,8 @@
 Cambridge, MA 02139, USA.  */
 
 #include <config.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <errno.h>
 #ifdef STDC_HEADERS
