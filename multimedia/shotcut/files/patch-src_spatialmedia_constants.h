--- src/spatialmedia/constants.h.orig	2020-12-28 20:21:17 UTC
+++ src/spatialmedia/constants.h
@@ -36,6 +36,8 @@
 #  define le64toh(x) qFromLittleEndian(x)
 #elif !defined(__FreeBSD__)
 #  include <endian.h>
+#elif defined(__FreeBSD__)
+#  include <sys/endian.h>
 #endif
 
 struct AudioMetadata {
