--- src/parser_lyb.c.orig	2019-03-14 23:35:14 UTC
+++ src/parser_lyb.c
@@ -23,6 +23,8 @@
 # define le16toh(x) OSSwapLittleToHostInt16(x)
 # define le32toh(x) OSSwapLittleToHostInt32(x)
 # define le64toh(x) OSSwapLittleToHostInt64(x)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+# include <sys/endian.h>
 #else
 # include <endian.h>
 #endif
