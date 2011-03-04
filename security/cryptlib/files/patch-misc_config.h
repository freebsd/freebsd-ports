--- misc/config.h.orig	2010-12-21 02:29:54.000000000 +0100
+++ misc/config.h	2011-03-04 15:31:57.000000000 +0100
@@ -287,6 +287,7 @@
 
 /* General device usage */
 
+#define USE_PKCS11
 #if defined( USE_PKCS11 ) || defined( USE_FORTEZZA ) || defined( USE_CRYPTOAPI )
   #define USE_DEVICES
 #endif /* Device types */
