--- src/tcs/ps/tcsps.c.orig	2016-06-20 15:21:26 UTC
+++ src/tcs/ps/tcsps.c
@@ -24,6 +24,11 @@
 #define LE_16 htole16
 #define LE_32 htole32
 #define LE_64 htole64
+#elif defined (HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
+#define LE_16 htole16
+#define LE_32 htole32
+#define LE_64 htole64
 #else
 #define LE_16(x) (x)
 #define LE_32(x) (x)
@@ -33,6 +38,26 @@
 #include <fcntl.h>
 #include <limits.h>
 
+#ifdef __sun
+#define LOCK_EX  F_LOCK 
+#define LOCK_UN  F_ULOCK 
+#define flock(fd, func) lockf(fd, func, 0)
+#endif
+
+#ifndef LOCK_SH
+#define   LOCK_SH   1    /* shared lock */
+#endif
+#ifndef LOCK_EX
+#define   LOCK_EX   2    /* exclusive lock */
+#endif
+#ifndef LOCK_NB
+#define   LOCK_NB   4    /* don't block when locking */
+#endif
+#ifndef LOCK_UN
+#define   LOCK_UN   8    /* unlock */
+#endif
+
+
 #include "trousers/tss.h"
 #include "trousers_types.h"
 #include "tcsps.h"
@@ -43,6 +68,25 @@
 #include "tcsd_wrap.h"
 #include "tcsd.h"
 
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
+
 int system_ps_fd = -1;
 MUTEX_DECLARE(disk_cache_lock);
 
