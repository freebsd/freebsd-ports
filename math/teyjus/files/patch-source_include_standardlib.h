--- source/include/standardlib.h.orig	2019-12-02 05:46:28 UTC
+++ source/include/standardlib.h
@@ -79,9 +79,9 @@ typedef unsigned __int64 u_int64_t;
 #    include <unistd.h>
 #    include <sys/endian.h>
 // Use the functions from byteorder(3)
-#    define bswap_16(x) swap16(x)
-#    define bswap_32(x) swap32(x)
-#    define bswap_64(x) swap64(x)
+#    define bswap_16(x) bswap16(x)
+#    define bswap_32(x) bswap32(x)
+#    define bswap_64(x) bswap64(x)
 // __WORDSIZE is non-standard and should be inferred otherhow
 #    if defined(__x86_64__) || defined(__amd64__) || defined(__LP64__)
 #      define __WORDSIZE 64
