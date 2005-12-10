--- src/daemon/common/commonMultimedia.ml.orig	Sat Dec 10 04:03:38 2005
+++ src/daemon/common/commonMultimedia.ml	Sat Dec 10 04:05:46 2005
@@ -764,14 +764,31 @@
  *	be done, then convert back.
  */
 
+#if defined(HAVE_SYS_PARAM_H) || ((defined(__unix__) || defined(unix)) && !defined(USG))
+#include <sys/param.h>
+#endif
+
 #include <inttypes.h>
 #include <netinet/in.h>
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+# include <sys/endian.h>
+# if (__FreeBSD_version >= 500000)
+#  define bswap_16(x) (bswap16(x))
+#  define bswap_32(x) (bswap32(x))
+# else
+#  define bswap_16(x) (be16toh(x))
+#  define bswap_32(x) (be32toh(x))
+# endif
+#else
+
 #define bswap_16(x) \
      ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
 #define bswap_32(x) \
      ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |  \
       (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
+
+#endif
 
 #define htoles(x) bswap_16(htons(x))
 #define htolel(x) bswap_32(htonl(x))
