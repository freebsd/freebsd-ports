--- src/scrypt.cpp.orig	2014-06-28 13:26:56.000000000 +0200
+++ src/scrypt.cpp	2014-07-05 19:42:46.000000000 +0200
@@ -33,6 +33,9 @@
 #include <stdint.h>
 #include <string.h>
 #include <openssl/sha.h>
+#if defined(__FreeBSD__) && (__FreeBSD_version < 100000)
+#include <sys/endian.h>
+#endif
 
 #ifndef __FreeBSD__
 /* Allready defined in sys/endian.h */
