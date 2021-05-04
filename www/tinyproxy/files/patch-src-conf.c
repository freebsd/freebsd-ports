--- src/conf.c.orig	2021-04-16 12:31:11 UTC
+++ src/conf.c
@@ -24,6 +24,7 @@
  */
 
 #include "common.h"
+#include <limits.h>
 #include <regex.h>
 #include "conf.h"
 
