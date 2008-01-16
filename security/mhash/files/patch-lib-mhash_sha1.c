diff -urN -x .svn ../../branches/vendor/mhash/lib/mhash_sha1.h ./lib/mhash_sha1.h
--- ../../branches/vendor/mhash/lib/mhash_sha1.h	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/mhash_sha1.h	2008-01-16 15:01:05.000000000 +0200
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
