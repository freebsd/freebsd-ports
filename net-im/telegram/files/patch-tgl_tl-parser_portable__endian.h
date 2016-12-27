--- tgl/tl-parser/portable_endian.h.orig	2015-10-17 13:33:25 UTC
+++ tgl/tl-parser/portable_endian.h
@@ -53,6 +53,7 @@
 
 #	include <sys/endian.h>
 
+#if !defined(__FreeBSD__)
 #	define be16toh(x) betoh16(x)
 #	define le16toh(x) letoh16(x)
 
@@ -61,6 +62,7 @@
 
 #	define be64toh(x) betoh64(x)
 #	define le64toh(x) letoh64(x)
+#endif /* !defined(__FreeBSD__) */
 
 #elif defined(__WINDOWS__)
 
