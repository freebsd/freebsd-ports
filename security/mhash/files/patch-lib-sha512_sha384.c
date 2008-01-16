diff -urN -x .svn ../../branches/vendor/mhash/lib/sha512_sha384.c ./lib/sha512_sha384.c
--- ../../branches/vendor/mhash/lib/sha512_sha384.c	2008-01-16 14:26:52.000000000 +0200
+++ ./lib/sha512_sha384.c	2008-01-16 14:57:58.000000000 +0200
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
 
