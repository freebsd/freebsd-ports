--- usr/lib/common/host_defs.h.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/common/host_defs.h
@@ -8,12 +8,23 @@
  * https://opensource.org/licenses/cpl1.0.php
  */
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #ifndef _HOST_DEFS_H
 #define _HOST_DEFS_H
 
 #include <pthread.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#ifdef _BYTE_ORDER
+#define	__BYTE_ORDER    _BYTE_ORDER
+#endif
+#ifdef _LITTLE_ENDIAN
+#define	__LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+#else
 #include <endian.h>
+#endif
 
 #include "pkcs32.h"
 #include <stdint.h>
