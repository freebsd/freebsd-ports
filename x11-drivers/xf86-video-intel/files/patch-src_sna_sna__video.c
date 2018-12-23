sna_video.c:62:10: fatal error: 'byteswap.h' file not found
#include <byteswap.h>
         ^~~~~~~~~~~~

--- src/sna/sna_video.c.orig	2018-12-03 09:01:25 UTC
+++ src/sna/sna_video.c
@@ -59,7 +59,12 @@
 #include "intel_options.h"
 
 #include <xf86xv.h>
+#if defined(__linux__) || defined(__GLIBC__)
 #include <byteswap.h>
+#else
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#endif
 
 #ifdef SNA_XVMC
 #define _SNA_XVMC_SERVER_
