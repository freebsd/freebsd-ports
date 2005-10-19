--- include/linux_compat.h.orig	Sun Oct  9 22:05:09 2005
+++ include/linux_compat.h	Sun Oct  9 22:05:09 2005
@@ -0,0 +1,6 @@
+#include <sys/types.h> /* XXX Or should it be sys/stdint.h ? */
+
+#define __u64 uint64_t
+#define __u32 uint32_t
+#define __s32 int32_t
+
