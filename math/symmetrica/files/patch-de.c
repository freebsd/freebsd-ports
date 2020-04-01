--- de.c.orig	2007-12-06 16:30:00 UTC
+++ de.c
@@ -1,4 +1,5 @@
 /* de.c SYMMETRICA */
+/* Patch from SageMath */
 #include "def.h"
 #include "macro.h"
 
@@ -24,7 +25,7 @@ OP cons_eins;   /* global INTEGER variable 1 */
 OP cons_negeins;/* global INTEGER variable -1 */
 OP cons_null;   /* global INTEGER variable 0 */
 FILE *texout;   /* global variable for texoutput */
-INT no_banner = FALSE; /* AK 281293 */
+INT no_banner = TRUE; /* AK 281293 */
 INT no_mem_check=TRUE; /* AK 100893 */
 INT english_tableau=FALSE; /* AK 290995 */
 
