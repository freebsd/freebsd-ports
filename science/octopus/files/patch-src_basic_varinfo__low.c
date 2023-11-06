- workaround for https://gitlab.com/octopus-code/octopus/-/issues/804

--- src/basic/varinfo_low.c.orig	2023-11-06 19:46:44 UTC
+++ src/basic/varinfo_low.c
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include "string_f.h" /* fortran <-> c string compatibility issues */
 
