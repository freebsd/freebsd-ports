--- ./src/myendian.h.orig	Mon Nov  1 20:23:03 2004
+++ ./src/myendian.h	Sun Nov 26 20:50:13 2006
@@ -8,7 +8,7 @@
 #    define BYTE_ORDER LITTLE_ENDIAN
 #  endif
 #else
-#  ifdef __NetBSD__
+#  if defined(__NetBSD__) || defined(__FreeBSD__)
 #    include <sys/endian.h>
 #  elif __APPLE__
 #    include <ppc/endian.h>
