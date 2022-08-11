--- test/test-functional.c.orig	2022-04-27 17:59:21 UTC
+++ test/test-functional.c
@@ -22,6 +22,7 @@
  * DEALINGS IN THE SOFTWARE.
  */
 
+#include <sys/wait.h>
 
 #include "config.h"
 
