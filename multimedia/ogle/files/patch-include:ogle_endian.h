--- include/ogle_endian.h.orig	Sun Nov 10 17:13:10 2002
+++ include/ogle_endian.h	Sun Nov 10 17:13:29 2002
@@ -27,2 +27,6 @@
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef WORDS_BIGENDIAN
@@ -38,5 +42,8 @@
 #  define FROM_BE_32(x) (bswap32(x))
-#elif defined(HAVE_SYS_ENDIAN_H)
+#elif defined(HAVE_SYS_ENDIAN_H) && !defined(__FreeBSD__)
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (swap32(x))
+#elif defined(HAVE_SYS_ENDIAN_H) && defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#  include <sys/endian.h>
+#  define FROM_BE_32(x) (be32toh(x))
 #else
