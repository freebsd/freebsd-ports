--- src/defines.h~	Sun Dec 11 21:13:26 2005
+++ src/defines.h	Mon Apr  9 17:28:13 2007
@@ -40,16 +40,25 @@
 #endif
   }
 
+#if defined(__FreeBSD__)
+#define mbo32(x) htobe32(x)
+#define htom32(x) htobe32(x)
+#define mbo16(x) htobe16(x)
+#define htom16(x) htobe16(x)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
-#define mbo32(x) (__bswap_constant_32(x))
+#define mbo32(x) \
+      ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
+       (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
 #define htom32(x) (__bswap_32(x))
-#define mbo16(x) (__bswap_constant_16(x))
+#define mbo16(x) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
 #define htom16(x) (__bswap_16(x))
 #else
 #define mbo32(x) (x)
 #define htom32(x) (x)
 #define mbo16(x) (x)
 #define htom16(x) (x)
+#endif
 #endif
 
 #define DVBCUT_QSETTINGS_DOMAIN "dvbcut.sf.net"
