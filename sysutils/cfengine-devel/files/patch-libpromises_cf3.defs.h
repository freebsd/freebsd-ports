--- libpromises/cf3.defs.h.orig	2023-12-04 08:49:45.000000000 -0800
+++ libpromises/cf3.defs.h	2023-12-05 21:29:59.417994000 -0800
@@ -1695,6 +1695,7 @@
 /* common macros                                                         */
 /*************************************************************************/
 
+#include <pcre.h>
 #include <rlist.h>
 #include <dbm_api.h>
 #include <sequence.h>
