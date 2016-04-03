--- src/libstrongswan/utils/utils/byteorder.h.orig	2016-03-29 06:56:52 UTC
+++ src/libstrongswan/utils/utils/byteorder.h
@@ -22,6 +22,10 @@
 #ifndef BYTEORDER_H_
 #define BYTEORDER_H_
 
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
+
 /**
  * Architecture independent bitfield definition helpers (at least with GCC).
  *
