--- src/libstrongswan/utils/utils/byteorder.h.orig	2023-03-27 21:00:49 UTC
+++ src/libstrongswan/utils/utils/byteorder.h
@@ -23,6 +23,10 @@
 #ifndef BYTEORDER_H_
 #define BYTEORDER_H_
 
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
+
 /**
  * Architecture independent bitfield definition helpers (at least with GCC).
  *
