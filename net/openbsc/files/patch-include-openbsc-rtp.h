--- include/openbsc/rtp.h.orig	2015-02-10 22:03:25 UTC
+++ include/openbsc/rtp.h
@@ -10,6 +10,12 @@
 #  define __BYTE_ORDER __DARWIN_BYTE_ORDER
 #  define __LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
 #  define __BIG_ENDIAN __DARWIN_BIG_ENDIAN
+# elif defined(__FreeBSD__)
+#  if __FreeBSD_version < 1000000
+#   include <machine/endian.h>
+#  else
+#   include <x86/endian.h>
+#  endif
 # else
 #  error "__BYTE_ORDER should be defined by someone"
 # endif
