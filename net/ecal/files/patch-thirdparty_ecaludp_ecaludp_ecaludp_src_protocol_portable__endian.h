--- thirdparty/ecaludp/ecaludp/ecaludp/src/protocol/portable_endian.h.orig	2024-05-14 02:01:15 UTC
+++ thirdparty/ecaludp/ecaludp/ecaludp/src/protocol/portable_endian.h
@@ -59,14 +59,14 @@
 
 #	include <sys/endian.h> // IWYU pragma: export
 
-#	define be16toh(x) betoh16(x)
-#	define le16toh(x) letoh16(x)
+//#	define be16toh(x) betoh16(x)
+//#	define le16toh(x) letoh16(x)
 
-#	define be32toh(x) betoh32(x)
-#	define le32toh(x) letoh32(x)
+//#	define be32toh(x) betoh32(x)
+//#	define le32toh(x) letoh32(x)
 
-#	define be64toh(x) betoh64(x)
-#	define le64toh(x) letoh64(x)
+//#	define be64toh(x) betoh64(x)
+//#	define le64toh(x) letoh64(x)
 
 #elif defined(__WINDOWS__)
 
