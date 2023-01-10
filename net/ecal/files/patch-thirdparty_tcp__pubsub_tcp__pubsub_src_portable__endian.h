--- thirdparty/tcp_pubsub/tcp_pubsub/src/portable_endian.h.orig	2023-01-10 09:58:29 UTC
+++ thirdparty/tcp_pubsub/tcp_pubsub/src/portable_endian.h
@@ -58,14 +58,14 @@
 
 #	include <sys/endian.h>
 
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
 
@@ -131,4 +131,4 @@
 
 #endif
 
-#endif
\ No newline at end of file
+#endif
