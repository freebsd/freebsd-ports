--- ./socket.h.orig	2005-11-01 12:06:11.000000000 +0100
+++ ./socket.h	2013-01-11 21:51:45.000000000 +0100
@@ -204,7 +204,7 @@
 
 #if PASSTOS_CAPABILITY
   /* used to get/set TOS. */
-  uint8_t ptos;
+  int ptos;
   bool ptos_defined;
 #endif
 
