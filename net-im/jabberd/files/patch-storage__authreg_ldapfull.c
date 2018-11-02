--- storage/authreg_ldapfull.c.orig	2018-11-01 20:14:26 UTC
+++ storage/authreg_ldapfull.c
@@ -29,6 +29,8 @@
  * !!! this blocks for every auth.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500	// need this to get crypt()
 #include "c2s.h"
 
