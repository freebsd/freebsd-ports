--- freebsd_nvme_ioctl.h.orig	2016-03-28 09:25:56.000000000 -0700
+++ freebsd_nvme_ioctl.h	2016-06-15 20:43:22.389493000 -0700
@@ -31,6 +31,7 @@
 
 #define	NVME_PASSTHROUGH_CMD	_IOWR('n', 0, struct nvme_pt_command)
 
+#if __FreeBSD_version < 1100110
 struct nvme_command
 {
 	/* dword 0 */
@@ -143,6 +144,7 @@
 	 */
 	struct mtx *		driver_lock;
 };
+#endif
 
 #define nvme_completion_is_error(cpl)					\
 	((cpl)->status.sc != 0 || (cpl)->status.sct != 0)
