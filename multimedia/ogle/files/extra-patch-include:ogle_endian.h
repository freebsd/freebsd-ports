--- include/ogle_endian.h.orig	Wed Mar  5 23:26:06 2003
+++ include/ogle_endian.h	Wed Mar  5 23:28:37 2003
@@ -45,6 +45,13 @@
 #elif defined(HAVE_SYS_ENDIAN_H) && defined(__FreeBSD__) && __FreeBSD_version >= 470000
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (be32toh(x))
+#elif defined(__FreeBSD__)
+#  define _KERNEL
+#  define I486_CPU     /* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#  define FROM_BE_32(x) (ntohl(x))
 #else
 #  warning "No accelerated byte swap found. Using slow c version."
 #  include <inttypes.h>
