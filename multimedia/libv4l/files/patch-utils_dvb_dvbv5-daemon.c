--- utils/dvb/dvbv5-daemon.c.orig	2022-01-10 11:49:59 UTC
+++ utils/dvb/dvbv5-daemon.c
@@ -18,7 +18,14 @@
  *
  */
 
-#define _XOPEN_SOURCE 600
+#ifdef __FreeBSD__
+#  include <sys/param.h>
+#  if __FreeBSD_version < 1500505 || (__FreeBSD_version >= 1600000 && __FreeBSD_version < 1600008)
+#    define tdestroy(...) do {} while (0)
+#  endif
+#else
+#  define _XOPEN_SOURCE 600
+#endif
 
 #define _FILE_OFFSET_BITS 64
 #define _LARGEFILE_SOURCE 1
