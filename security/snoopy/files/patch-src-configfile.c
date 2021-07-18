--- src/configfile.c.orig	2020-12-07 03:14:46 UTC
+++ src/configfile.c
@@ -35,9 +35,6 @@
 
 #include "lib/inih/src/ini.h"
 
-#ifndef   _XOPEN_SOURCE   // For strdup
-#define   _XOPEN_SOURCE   500
-#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
