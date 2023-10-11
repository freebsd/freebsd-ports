Drop after FreeBSD 12.4 EOL around 2023-12-31.
https://cgit.freebsd.org/src/commit/?id=1dd126163b94

In file included from ../src/modules/module-netjack2-manager.c:38:
../src/modules/module-netjack2/peer.c:2:10: fatal error: 'byteswap.h' file not found
#include <byteswap.h>
         ^~~~~~~~~~~~

--- src/modules/module-netjack2/peer.c.orig	2023-10-06 09:37:06 UTC
+++ src/modules/module-netjack2/peer.c
@@ -1,5 +1,12 @@
 
+#if __has_include(<byteswap.h>)
 #include <byteswap.h>
+#else
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+#endif
 
 #ifdef HAVE_OPUS_CUSTOM
 #include <opus/opus.h>
