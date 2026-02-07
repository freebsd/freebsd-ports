--- plugins/pptpd-logwtmp.c.orig	2012-02-13 10:53:17.000000000 +0800
+++ plugins/pptpd-logwtmp.c	2012-02-13 10:53:26.000000000 +0800
@@ -10,7 +10,6 @@
  *  2 of the License, or (at your option) any later version.
  */
 #include <unistd.h>
-#include <utmp.h>
 #include <string.h>
 #include <pppd/pppd.h>
 
