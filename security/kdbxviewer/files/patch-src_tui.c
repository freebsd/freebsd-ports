--- src/tui.c.orig	2021-10-04 12:08:30 UTC
+++ src/tui.c
@@ -13,7 +13,7 @@
 #include <locale.h>
 #include "helper.h"
 
-int unmask;
+extern int unmask;
 #define WIDE(str) stfl_ipool_towc(ipool, str)
 #define MAXFIELDLEN 32768
 
