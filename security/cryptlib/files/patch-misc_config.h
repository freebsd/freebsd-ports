--- misc/config.h.orig	2011-08-14 01:40:52.000000000 +0200
+++ misc/config.h	2012-01-10 12:45:17.000000000 +0100
@@ -280,6 +280,7 @@
 
 /* General device usage */
 
+#define USE_PKCS11
 #if defined( USE_PKCS11 ) || defined( USE_CRYPTOAPI )
   #define USE_DEVICES
 #endif /* Device types */
