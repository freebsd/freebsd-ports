--- storage/authreg_ldapfull.c.orig	2016-05-03 18:51:56 UTC
+++ storage/authreg_ldapfull.c
@@ -29,6 +29,8 @@
  * !!! this blocks for every auth.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500	// need this to get crypt()
 #include "c2s.h"
 
