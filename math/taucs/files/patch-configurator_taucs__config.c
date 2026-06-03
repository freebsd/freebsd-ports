https://github.com/sivantoledo/taucs/pull/2

--- configurator/taucs_config.c.orig	2003-09-04 09:08:32 UTC
+++ configurator/taucs_config.c
@@ -2,6 +2,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+extern int mkdir();
+
 #include "taucs_structure.h"
 
 #define INPUT_LEN 1024
