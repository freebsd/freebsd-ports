--- lib/xvid/bitstream/h263.h.orig	Wed Nov 13 16:53:29 2002
+++ lib/xvid/bitstream/h263.h	Wed Nov 13 16:55:31 2002
@@ -25,6 +25,10 @@
 /* #define FFMPEG_VERSION_INT 0x000405 */
 /* #define FFMPEG_VERSION     "0.4.5" */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef WIN32
 #define CONFIG_WIN32
 #endif
@@ -69,11 +73,16 @@
 #define DEBUG
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#define be2me_32(x) (be32toh(x))
+#else
 // code from bits/byteswap.h (C) 1997, 1998 Free Software Foundation, Inc.
 #define bswap_32(x) \
      ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
       (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
 #define be2me_32(x) bswap_32(x)
+#endif
 
 #define snprintf _snprintf
 
