--- src/common/common.h.orig	2016-11-29 22:48:37 UTC
+++ src/common/common.h
@@ -19,6 +19,14 @@
 #ifndef _COMMON_H
 #define _COMMON_H
 
+#if defined(__FreeBSD__)
+
+#include <sys/endian.h>
+
+#define ENODATA ENOATTR
+
+#endif
+
 #include "error.h"
 #include "macros.h"
 #include "runas.h"
