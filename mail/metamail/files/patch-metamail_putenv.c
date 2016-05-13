--- metamail/putenv.c.orig	1993-10-12 16:17:43 UTC
+++ metamail/putenv.c
@@ -17,6 +17,8 @@ not, write to the Free Software Foundati
 Cambridge, MA 02139, USA.  */
 
 #include <config.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <errno.h>
 #ifdef STDC_HEADERS
@@ -48,7 +50,11 @@ extern char **environ;
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
