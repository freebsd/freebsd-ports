--- src/nsysctl.c.orig	2021-02-09 21:47:51 UTC
+++ src/nsysctl.c
@@ -25,7 +25,9 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/types.h>
 #include <sys/queue.h>
+#include <sys/sysctl.h>
 
 #include <inttypes.h>
 #include <libutil.h>
