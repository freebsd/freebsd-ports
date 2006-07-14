--- misc/config.h.orig	Fri Jul 14 08:18:03 2006
+++ misc/config.h	Fri Jul 14 08:19:19 2006
@@ -168,6 +168,7 @@
 
 /* General device usage */
 
+#define USE_PKCS11
 #if defined( USE_PKCS11 ) || defined( USE_FORTEZZA ) || defined( USE_CRYPTOAPI )
   #define USE_DEVICES
 #endif /* Device types */
