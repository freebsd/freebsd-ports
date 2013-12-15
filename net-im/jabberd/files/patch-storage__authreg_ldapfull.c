--- ./storage/authreg_ldapfull.c.orig	2013-10-07 16:27:54.000000000 +0100
+++ ./storage/authreg_ldapfull.c	2013-12-15 10:29:42.316778126 +0000
@@ -29,6 +29,8 @@
  * !!! this blocks for every auth.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500	// need this to get crypt()
 #include "c2s.h"
 
