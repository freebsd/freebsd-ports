--- src/utils/lib/sha1_c.c.orig	Sat Dec 10 03:57:38 2005
+++ src/utils/lib/sha1_c.c	Sat Dec 10 04:02:54 2005
@@ -62,6 +62,19 @@
 #  include <byteswap.h>
 #endif
 
+#if defined(HAVE_SYS_PARAM_H) || ((defined(__unix__) || defined(unix)) && !defined(USG))
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+# include <sys/endian.h>
+# if (__FreeBSD_version >= 500000)
+#  define bswap_32(x) (bswap32(x))
+# else
+#  define bswap_32(x) (be32toh(x))
+# endif
+#endif
+
 #define BRG_LITTLE_ENDIAN   1234 /* byte 0 is least significant (i386) */
 #define BRG_BIG_ENDIAN      4321 /* byte 0 is most significant (mc68k) */
 
