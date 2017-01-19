--- lib/ipmi_cfgp.c.orig	2016-08-21 06:59:27 UTC
+++ lib/ipmi_cfgp.c
@@ -30,7 +30,7 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <ipmitool/helper.h>
