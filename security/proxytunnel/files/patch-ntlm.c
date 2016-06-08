--- ntlm.c.orig	2008-02-22 22:20:41.000000000 +0100
+++ ntlm.c	2015-02-28 20:50:11.141553420 +0100
@@ -28,8 +28,9 @@
 #include "proxytunnel.h"
 #include <ctype.h>
 #include <sys/time.h>
-#include <openssl/md4.h>
-#include <openssl/md5.h>
+#include <sys/types.h>
+#include <md4.h>
+#include <md5.h>
 
 #define TYPE1_DATA_SEG 8
 #define TYPE2_BUF_SIZE 2048
@@ -256,9 +257,9 @@
 	/* if key is longer than 64 bytes reset it to key=MD5(key) */
 	if (key_len > 64) {
 		MD5_CTX tctx;
-		MD5_Init( &tctx );
-		MD5_Update( &tctx, key, key_len );
-		MD5_Final( tk, &tctx );
+		MD5Init( &tctx );
+		MD5Update( &tctx, key, key_len );
+		MD5Final( tk, &tctx );
 		key = tk;
 		key_len = 16;
 	}
@@ -287,16 +288,16 @@
 	}
 
 	/* perform inner MD5 */
-	MD5_Init(&context);                   /* init context for 1st pass */
-	MD5_Update(&context, k_ipad, 64);     /* start with inner pad */
-	MD5_Update(&context, text, text_len); /* then text of datagram */
-	MD5_Final(digest, &context);          /* finish up 1st pass */
+	MD5Init(&context);                   /* init context for 1st pass */
+	MD5Update(&context, k_ipad, 64);     /* start with inner pad */
+	MD5Update(&context, text, text_len); /* then text of datagram */
+	MD5Final(digest, &context);          /* finish up 1st pass */
 
 	/* perform outer MD5 */
-	MD5_Init(&context);                   /* init context for 2nd pass */
-	MD5_Update(&context, k_opad, 64);     /* start with outer pad */
-	MD5_Update(&context, digest, 16);     /* then results of 1st hash */
-	MD5_Final(digest, &context);          /* finish up 2nd pass */
+	MD5Init(&context);                   /* init context for 2nd pass */
+	MD5Update(&context, k_opad, 64);     /* start with outer pad */
+	MD5Update(&context, digest, 16);     /* then results of 1st hash */
+	MD5Final(digest, &context);          /* finish up 2nd pass */
 }
 
 void build_ntlm2_response() {
@@ -327,9 +328,9 @@
 		}
 	}
 
-	MD4_Init (&passcontext);
-	MD4_Update (&passcontext, unipasswd, passlen);
-	MD4_Final (passdigest, &passcontext);
+	MD4Init (&passcontext);
+	MD4Update (&passcontext, unipasswd, passlen);
+	MD4Final (passdigest, &passcontext);
 
 	if( args_info.verbose_flag ) {
 		message("NTLM: MD4 of password is: ");
