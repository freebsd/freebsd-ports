--- main.c.orig	2026-02-12 17:45:38 UTC
+++ main.c
@@ -21,6 +21,8 @@
  * 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#include <ctype.h>
+#include <string.h>
 #include <unistd.h>
 #include "timers.h"
 #include "bb.h"
