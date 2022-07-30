--- libddr_lzo.c.orig	2022-07-26 13:53:37 UTC
+++ libddr_lzo.c
@@ -13,6 +13,8 @@
 #define _LARGEFILE64_SOURCE 1
 #define _FILE_OFFSET_BITS 64
 
+#include "config.h"
+
 #include "ddr_plugin.h"
 #include "ddr_ctrl.h"
 
@@ -48,6 +50,7 @@
 #error __WORDSIZE unknown
 #endif
 
+#define HAVE_BASENAME 1
 #ifdef HAVE_BASENAME
 //char* basename(char*);
 #else
