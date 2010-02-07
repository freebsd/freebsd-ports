--- ciso.h.orig	2010-02-07 16:32:56.000000000 +0100
+++ ciso.h	2010-02-07 16:33:38.000000000 +0100
@@ -19,6 +19,8 @@
     Copyright 2005 BOOSTER
 */
 
+#include <stdint.h>
+
 
 #ifndef __CISO_H__
 #define __CISO_H__
@@ -28,9 +30,9 @@
 typedef struct ciso_header
 {
 	unsigned char magic[4];			/* +00 : 'C','I','S','O'                 */
-	unsigned long header_size;		/* +04 : header size (==0x18)            */
+	uint32_t header_size;		/* +04 : header size (==0x18)            */
 	unsigned long long total_bytes;	/* +08 : number of original data size    */
-	unsigned long block_size;		/* +10 : number of compressed block size */
+	uint32_t block_size;		/* +10 : number of compressed block size */
 	unsigned char ver;				/* +14 : version 01                      */
 	unsigned char align;			/* +15 : align of index value            */
 	unsigned char rsv_06[2];		/* +16 : reserved                        */
