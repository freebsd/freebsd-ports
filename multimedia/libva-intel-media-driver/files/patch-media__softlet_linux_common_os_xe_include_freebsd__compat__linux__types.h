--- media_softlet/linux/common/os/xe/include/freebsd_compat_linux_types.h.orig	2026-05-18 12:43:46 UTC
+++ media_softlet/linux/common/os/xe/include/freebsd_compat_linux_types.h
@@ -0,0 +1,13 @@
+#ifndef _FREEBSD_COMPAT_LINUX_TYPES_H
+#define _FREEBSD_COMPAT_LINUX_TYPES_H
+
+#include <sys/types.h>
+#include <stdint.h>
+
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
+typedef int32_t __s32;
+
+#endif
