--- common/constants.h.orig	Thu Mar 23 18:15:07 2006
+++ common/constants.h	Thu Jan 18 14:57:54 2007
@@ -16,6 +16,8 @@
  * 2003/06/23 - EvB - Added constants needed for accept/reject/acctresp ops.
  */
 
+/* Required for LONG_MAX */
+#include <limits.h>
 
 /*
  * DEFINES

