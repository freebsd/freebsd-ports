--- ./socket.h.orig	2011-12-13 17:58:56.000000000 +0100
+++ ./socket.h	2013-01-11 21:50:11.000000000 +0100
@@ -225,7 +225,7 @@
 
 #if PASSTOS_CAPABILITY
   /* used to get/set TOS. */
-  uint8_t ptos;
+  int ptos;
   bool ptos_defined;
 #endif
 
