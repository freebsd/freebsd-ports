--- freebsd_nvme_ioctl.h.orig	2017-09-20 10:34:38.000000000 -0700
+++ freebsd_nvme_ioctl.h	2018-02-22 23:04:32.250104000 -0800
@@ -148,8 +148,10 @@
 #include <dev/nvme/nvme.h>
 #endif
 
+#if __FreeBSD_version < 1200058
 #define nvme_completion_is_error(cpl)					\
 	((cpl)->status.sc != 0 || (cpl)->status.sct != 0)
+#endif
 
 #define NVME_CTRLR_PREFIX	"/dev/nvme"
 #define NVME_NS_PREFIX		"ns"
