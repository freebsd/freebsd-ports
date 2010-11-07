--- src/tcs/ps/ps_utils.c.orig	2010-07-01 00:15:00.000000000 +0900
+++ src/tcs/ps/ps_utils.c	2010-10-24 21:04:04.832556427 +0900
@@ -16,10 +16,18 @@
 #if defined(HAVE_BYTEORDER_H)
 #include <sys/byteorder.h>
 #elif defined(HTOLE_DEFINED)
+#if defined(HAVE_ENDIAN_H)
 #include <endian.h>
 #define LE_16 htole16
 #define LE_32 htole32
 #define LE_64 htole64
+#endif
+#if defined(HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
+#define LE_16 htole16
+#define LE_32 htole32
+#define LE_64 htole64
+#endif
 #else
 #define LE_16(x) (x)
 #define LE_32(x) (x)
@@ -39,6 +47,24 @@
 #include "tcs_utils.h"
 #include "tcslog.h"
 
+#ifndef LE_16
+static UINT16 htole16(UINT16 x)
+{
+    BYTE *b = &x;
+    return (UINT16) (b[0] + (b[1] << 8));
+}
+#define LE_16 htole16
+#endif
+
+#ifndef LE_32
+static UINT32 htole32(UINT32 x)
+{
+    BYTE *b = &x;
+    return (UINT32) (b[0] + (b[1] << 8) + (b[2] << 16) + (b[3] << 24));
+}
+#define LE_32 htole32
+#endif
+
 struct key_disk_cache *key_disk_cache_head = NULL;
 
 
