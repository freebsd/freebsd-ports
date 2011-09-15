--- mtrr.c.orig	2011-09-15 15:38:23.000000000 -0700
+++ mtrr.c	2011-09-15 15:38:31.000000000 -0700
@@ -8,7 +8,9 @@
  */
 
 #include <stdio.h>
+#ifdef __linux__
 #include <asm/mtrr.h>
+#endif
 #include "x86info.h"
 
 #define IA32_MTRRCAP_SMRR 0x800
@@ -25,7 +27,7 @@
 
 static unsigned int max_phy_addr = 0;
 
-static char * mtrr_types[MTRR_NUM_TYPES] =
+static char * mtrr_types[] =
 {
     "uncacheable",
     "write-combining",
