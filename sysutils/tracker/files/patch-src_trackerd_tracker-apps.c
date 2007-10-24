--- ./src/trackerd/tracker-apps.c.orig	2007-10-05 20:18:39.000000000 +0400
+++ ./src/trackerd/tracker-apps.c	2007-10-05 20:19:10.000000000 +0400
@@ -18,7 +18,8 @@
  * Boston, MA  02110-1301, USA.
  */
 
-#include<string.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "tracker-apps.h"
 #include "tracker-db.h"
