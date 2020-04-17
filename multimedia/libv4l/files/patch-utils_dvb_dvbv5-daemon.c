--- utils/dvb/dvbv5-daemon.c.orig	2020-04-09 16:29:54 UTC
+++ utils/dvb/dvbv5-daemon.c
@@ -18,7 +18,11 @@
  *
  */
 
+#ifndef __FreeBSD__
 #define _XOPEN_SOURCE 600
+#else
+#define	tdestroy(...) do {} while (0)
+#endif
 
 #define _FILE_OFFSET_BITS 64
 #define _LARGEFILE_SOURCE 1
