
$FreeBSD$

--- pcapu.c.orig	Mon Mar  3 17:55:38 2003
+++ pcapu.c	Mon Mar  3 17:56:03 2003
@@ -47,8 +47,8 @@
 #include "config.h"
 
 struct phdr { 
-  unsigned long saddr;
-  unsigned long daddr;
+  in_addr_t saddr;
+  in_addr_t daddr;
   char zero;
   unsigned char protocol;
   unsigned short length;
