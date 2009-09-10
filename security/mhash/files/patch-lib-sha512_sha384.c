Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/sha512_sha384.c.orig
+++ lib/sha512_sha384.c
@@ -129,13 +129,13 @@
 #endif
 
 #define STRING2INT64(s) ((((((((((((((mutils_word64)(EXTRACT_UCHAR(s) << 8)    \
-			 | EXTRACT_UCHAR(s+1)) << 8)  \
-			 | EXTRACT_UCHAR(s+2)) << 8)  \
-			 | EXTRACT_UCHAR(s+3)) << 8)  \
-			 | EXTRACT_UCHAR(s+4)) << 8)  \
-			 | EXTRACT_UCHAR(s+5)) << 8)  \
-			 | EXTRACT_UCHAR(s+6)) << 8)  \
-			 | EXTRACT_UCHAR(s+7))
+			 | EXTRACT_UCHAR((s)+1)) << 8)  \
+			 | EXTRACT_UCHAR((s)+2)) << 8)  \
+			 | EXTRACT_UCHAR((s)+3)) << 8)  \
+			 | EXTRACT_UCHAR((s)+4)) << 8)  \
+			 | EXTRACT_UCHAR((s)+5)) << 8)  \
+			 | EXTRACT_UCHAR((s)+6)) << 8)  \
+			 | EXTRACT_UCHAR((s)+7))
 
 /* Initialize the SHA512/384 values */
 
