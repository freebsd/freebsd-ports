--- lib/chunkio/deps/crc32/crc32.c.orig	2018-12-20 18:13:51 UTC
+++ lib/chunkio/deps/crc32/crc32.c
@@ -29,6 +29,8 @@
 #  define htole16(x) (x)
 #  define be16toh(x) ntohs(x)
 #  define le16toh(x) (x)
+#elif defined(__FreeBSD__)
+#  include <sys/endian.h>
 #else
 #  include <endian.h>
 #endif
