--- src/kpass.c.orig	2013-04-01 18:36:50.878364960 +0000
+++ src/kpass.c	2013-04-01 18:37:43.162887560 +0000
@@ -23,7 +23,11 @@
 #include <nettle/aes.h>
 #include <nettle/sha.h>
 #include <nettle/cbc.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <byteswap.h>
+#endif
 #include <time.h>
 
 #include <libintl.h>
