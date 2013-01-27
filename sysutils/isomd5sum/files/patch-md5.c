--- ./md5.c.orig	2012-10-09 13:34:42.000000000 +0300
+++ ./md5.c	2012-10-09 13:34:51.000000000 +0300
@@ -20,13 +20,13 @@
  */
 
 #include <string.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include "md5.h"
 
 void MD5_Transform(uint32 *buf, uint32 const *in);
 
-#define IS_BIG_ENDIAN() (__BYTE_ORDER == __BIG_ENDIAN)
-#define IS_LITTLE_ENDIAN() (__BYTE_ORDER == __LITTLE_ENDIAN)
+#define IS_BIG_ENDIAN() (_BYTE_ORDER == _BIG_ENDIAN)
+#define IS_LITTLE_ENDIAN() (_BYTE_ORDER == _LITTLE_ENDIAN)
 
 static void byteReverse(unsigned char *buf, unsigned longs);
 
@@ -157,7 +157,7 @@
 	MD5_Transform(ctx->buf, (uint32 *) ctx->in);
 	if (ctx->doByteReverse) byteReverse((unsigned char *) ctx->buf, 4);
 	memcpy(digest, ctx->buf, 16);
-	memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
+	memset(ctx, 0, sizeof(*ctx));	/* In case it's sensitive */
 }
 
 #ifndef ASM_MD5
