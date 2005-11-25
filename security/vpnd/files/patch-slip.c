--- slip.c.orig	Tue Aug 30 15:51:20 2005
+++ slip.c	Thu Sep 15 16:42:01 2005
@@ -18,6 +18,7 @@
  */
 
 #include "vpnd.h"
+#include <net/if_slvar.h>
 
 /*============================================================================*/
 /* slippery: slip interface creation and deletion                             */
