--- include/ogle_endian.h.orig	Thu Oct  4 00:41:49 2001
+++ include/ogle_endian.h	Thu Oct 10 12:08:36 2002
@@ -36,7 +36,7 @@
 #elif defined(HAVE_SYS_BSWAP_H)
 #  include <sys/bswap.h>
 #  define FROM_BE_32(x) (bswap32(x))
-#elif defined(HAVE_SYS_ENDIAN_H)
+#elif defined(HAVE_SYS_ENDIAN_H) && !defined(__FreeBSD__)
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (swap32(x))
 #else
