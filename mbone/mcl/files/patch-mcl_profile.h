--- src/alc/mcl_profile.h.orig	Tue Dec 16 23:47:58 2003
+++ src/alc/mcl_profile.h	Tue Dec 16 23:48:09 2003
@@ -130,7 +130,7 @@
 /*
  * Do you want to use LDPC large block Forward Error Correction (FEC) ?
  */
-#define LDPC_FEC
+//#define LDPC_FEC
 
 #if defined(RSE_FEC) || defined(LDPC_FEC)
 #define FEC
