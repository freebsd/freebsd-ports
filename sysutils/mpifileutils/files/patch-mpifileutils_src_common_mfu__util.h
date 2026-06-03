--- mpifileutils/src/common/mfu_util.h.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_util.h
@@ -9,6 +9,10 @@ extern "C" {
 #ifndef MFU_UTIL_H
 #define MFU_UTIL_H
 
+#ifndef O_NOATIME
+#define O_NOATIME 0
+#endif
+
 #include <stdlib.h>
 #include <stdarg.h>
 #include <stdint.h>
