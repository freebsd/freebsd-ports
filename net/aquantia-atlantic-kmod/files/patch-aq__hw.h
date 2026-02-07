--- aq_hw.h.orig	2023-11-07 23:05:23 UTC
+++ aq_hw.h
@@ -42,6 +42,14 @@
 #include <sys/endian.h>
 #include "aq_common.h"
 
+#ifndef readl
+#define readl(va)       (*(volatile uint32_t *) (va))
+#endif
+
+#ifndef writel
+#define writel(va, d)   (*(volatile uint32_t *) (va) = (d))
+#endif
+
 #define AQ_WRITE_REG(hw, reg, value) writel(((hw)->hw_addr + (reg)), htole32(value))
     
 #define AQ_READ_REG(hw, reg) le32toh(readl((hw)->hw_addr + reg))
