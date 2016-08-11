--- tgl/tl-parser/portable_endian.h.orig	2016-08-11 06:34:54 UTC
+++ tgl/tl-parser/portable_endian.h
@@ -53,15 +53,6 @@
 
 #	include <sys/endian.h>
 
-#	define be16toh(x) betoh16(x)
-#	define le16toh(x) letoh16(x)
-
-#	define be32toh(x) betoh32(x)
-#	define le32toh(x) letoh32(x)
-
-#	define be64toh(x) betoh64(x)
-#	define le64toh(x) letoh64(x)
-
 #elif defined(__WINDOWS__)
 
 #	include <winsock2.h>
