# $FreeBSD$
--- src/md5.h.orig	2004-03-17 07:09:31.000000000 -0800
+++ src/md5.h	2009-05-07 19:41:20.000000000 -0700
@@ -22,14 +22,16 @@
 documentation and/or software.
  */
 
+#include <stdint.h>
+
 /* POINTER defines a generic pointer type */
 typedef unsigned char *POINTER;
 
 /* UINT2 defines a two byte word */
-typedef unsigned short int UINT2;
+typedef uint16_t UINT2;
 
 /* UINT4 defines a four byte word */
-typedef unsigned long int UINT4;
+typedef uint32_t UINT4;
 
 /* MD5 context. */
 typedef struct {
