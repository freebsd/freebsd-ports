--- src/configfile.c.orig	2016-09-14 15:02:26 UTC
+++ src/configfile.c
@@ -35,9 +35,6 @@
 
 #include "lib/inih/src/ini.h"
 
-#ifndef   _XOPEN_SOURCE   // For strdup
-#define   _XOPEN_SOURCE   500
-#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
