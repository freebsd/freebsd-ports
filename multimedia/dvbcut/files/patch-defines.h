--- src/defines.h~	Sun Dec 11 21:13:26 2005
+++ src/defines.h	Mon Dec 19 23:05:03 2005
@@ -40,6 +40,12 @@
 #endif
   }
 
+#if defined(__FreeBSD__)
+#define mbo32(x) htobe32(x)
+#define htom32(x) htobe32(x)
+#define mbo16(x) htobe16(x)
+#define htom16(x) htobe16(x)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define mbo32(x) (__bswap_constant_32(x))
 #define htom32(x) (__bswap_32(x))
@@ -50,6 +56,7 @@
 #define htom32(x) (x)
 #define mbo16(x) (x)
 #define htom16(x) (x)
+#endif
 #endif
 
 #define DVBCUT_QSETTINGS_DOMAIN "dvbcut.sf.net"
