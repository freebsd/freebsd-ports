--- include/ogle_endian.h.orig	Sun Apr 13 12:43:23 2003
+++ include/ogle_endian.h	Mon Nov 28 16:46:40 2005
@@ -48,8 +48,21 @@
 #  define FROM_BE_32(x) (swap32(x))
 #elif defined(HAVE_SYS_ENDIAN_H) && defined(__FreeBSD__) && __FreeBSD_version >= 470000
 #  include <sys/endian.h>
+#  if (__FreeBSD_version >= 500000)
+#   define FROM_BE_16(x) (bswap16(x))
+#   define FROM_BE_32(x) (bswap32(x))
+#  else
 #  define FROM_BE_16(x) (be16toh(x))
 #  define FROM_BE_32(x) (be32toh(x))
+#  endif
+#elif defined(__FreeBSD__)
+#  define _KERNEL
+#  define I486_CPU     /* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#  define FROM_BE_16(x) (ntohs(x))
+#  define FROM_BE_32(x) (ntohl(x))
 #else
 #  warning "No accelerated byte swap found. Using slow c version."
 #  include <inttypes.h>
