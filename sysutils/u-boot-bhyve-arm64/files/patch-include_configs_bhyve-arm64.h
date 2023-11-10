--- include/configs/bhyve-arm64.h.orig	2023-11-01 18:14:48 UTC
+++ include/configs/bhyve-arm64.h
@@ -0,0 +1,29 @@
+/* SPDX-License-Identifier: GPL-2.0+ */
+/*
+ * Copyright (c) 2017 Tuomas Tynkkynen
+ */
+
+#ifndef __CONFIG_H
+#define __CONFIG_H
+
+#include <linux/sizes.h>
+
+#define CFG_SYS_SDRAM_BASE	0x100000000
+
+#define CFG_PL011_CLOCK		24000000
+#define CFG_PL01x_PORTS		{(void *)CFG_SYS_SERIAL0}
+
+#define CFG_SYS_SERIAL0		0x10000
+
+#define BOOT_TARGET_DEVICES(func)	\
+	func(VIRTIO, virtio, 0)
+
+#include <config_distro_bootcmd.h>
+
+#define CFG_EXTRA_ENV_SETTINGS	\
+	"fdtfile=bhyve-arm.dst\0"	\
+	"fdt_addr_r=0x100100000\0"	\
+	"kernel_addr_r=0x100200000\0"	\
+	BOOTENV
+
+#endif /* __CONFIG_H */
