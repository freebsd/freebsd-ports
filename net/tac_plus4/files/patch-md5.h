--- md5.h.orig	Sat Apr  5 00:06:25 2003
+++ md5.h	Sat Apr  5 00:05:08 2003
@@ -54,7 +54,7 @@
 #if defined(CISCO_MD5_MODS)
 
 /* typedef a 32-bit type */
-typedef unsigned long int UINT4;
+typedef unsigned int UINT4;
 
 /* typedef a generic pointer type */
 typedef unsigned char *POINTER;
