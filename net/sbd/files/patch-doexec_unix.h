--- doexec_unix.h.orig	Sat Sep 11 06:07:51 2004
+++ doexec_unix.h	Sat Sep 18 18:48:27 2004
@@ -19,6 +19,7 @@
  * See the COPYING file for more information.
  */
 
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/types.h>
