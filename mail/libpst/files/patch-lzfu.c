--- lzfu.c.orig	Mon Sep 26 17:26:39 2005
+++ lzfu.c	Mon Sep 26 17:26:58 2005
@@ -16,7 +16,7 @@
 #include <stdio.h>
 
 #ifndef _MSC_VER
-#include <stdint.h>
+#include <inttypes.h>
 #endif
 
 #ifdef _MSC_VER
