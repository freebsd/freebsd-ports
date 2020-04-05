--- src/basic/varinfo_low.c.orig	2020-04-04 23:41:39 UTC
+++ src/basic/varinfo_low.c
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <fortran_types.h>
+#include <sys/types.h>
 
 #include "string_f.h" /* fortran <-> c string compatibility issues */
 
