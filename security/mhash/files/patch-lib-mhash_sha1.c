Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/mhash_sha1.h.orig
+++ lib/mhash_sha1.h
@@ -39,9 +39,9 @@
 #endif
 
 #define STRING2INT(s) ((((((EXTRACT_UCHAR(s) << 8)    \
-			 | EXTRACT_UCHAR(s+1)) << 8)  \
-			 | EXTRACT_UCHAR(s+2)) << 8)  \
-			 | EXTRACT_UCHAR(s+3))
+			 | EXTRACT_UCHAR((s)+1)) << 8)  \
+			 | EXTRACT_UCHAR((s)+2)) << 8)  \
+			 | EXTRACT_UCHAR((s)+3))
 #else
 mutils_word32 STRING2INT(mutils_word8 *s)
 {
