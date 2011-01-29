--- base64.c.orig	2010-07-05 14:55:31.000000000 +0400
+++ base64.c	2010-07-05 14:56:37.000000000 +0400
@@ -13,6 +13,7 @@
  * Removed unneeded encode function. 2004-07-17 David L. Parsley
  * parsley@linuxjedi.org
  */
+#include <sys/time.h>
 #include <ctype.h>
 #include "omcmd.h"
 
