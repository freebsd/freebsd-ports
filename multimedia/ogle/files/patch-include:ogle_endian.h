--- include/ogle_endian.h.orig	Sun Nov 10 17:13:10 2002
+++ include/ogle_endian.h	Sun Nov 10 17:13:29 2002
@@ -36,6 +36,9 @@
 #elif defined(HAVE_SYS_BSWAP_H)
 #  include <sys/bswap.h>
 #  define FROM_BE_32(x) (bswap32(x))
-#elif defined(HAVE_SYS_ENDIAN_H)
+#elif defined(HAVE_SYS_ENDIAN_H) && !defined(__FreeBSD__)
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (swap32(x))
+#elif defined(HAVE_SYS_ENDIAN_H) && defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#  include <sys/endian.h>
+#  define FROM_BE_32(x) (be32toh(x))
