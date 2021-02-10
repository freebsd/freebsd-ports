--- src/sysctlinfo_helper.c.orig	2021-02-09 21:52:37 UTC
+++ src/sysctlinfo_helper.c
@@ -25,6 +25,10 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/types.h>
+#include <sys/queue.h>
+#include <sys/sysctl.h>
+
 #include <stdbool.h>
 #include <stdlib.h>
 #include <string.h>
