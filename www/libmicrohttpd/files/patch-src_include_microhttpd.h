--- src/include/microhttpd.h.orig	2026-11-21 08:45:59 UTC
+++ src/include/microhttpd.h
@@ -101,7 +101,7 @@ MHD_C_DECLRATIONS_START_HERE_
  * they are parsed as decimal numbers.
  * Example: 0x01093001 = 1.9.30-1.
  */
-#define MHD_VERSION 0x01001000
+#define MHD_VERSION 0x01001100
 
 /* If generic headers don't work on your platform, include headers
    which define 'va_list', 'size_t', 'ssize_t', 'intptr_t', 'off_t',
