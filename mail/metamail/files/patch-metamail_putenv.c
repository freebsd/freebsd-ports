--- metamail/putenv.c.orig	Tue Oct 12 17:17:43 1993
+++ metamail/putenv.c	Sat Jul 14 17:35:44 2007
@@ -17,6 +17,8 @@
 Cambridge, MA 02139, USA.  */
 
 #include <config.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <errno.h>
 #ifdef STDC_HEADERS
@@ -48,7 +50,11 @@
 /* Put STRING, which is of the form "NAME=VALUE", in the environment.  */
 int
 putenv (string)
+#if defined __FreeBSD__ && __FreeBSD__ <= 6
      const char *string;
+#else
+     char *string;
+#endif
 {
   char *name_end = index (string, '=');
   register size_t size;
