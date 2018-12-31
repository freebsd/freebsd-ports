--- include/freebsd_nvme_ioctl.h.orig	2018-02-28 03:48:11 UTC
+++ include/freebsd_nvme_ioctl.h
@@ -151,12 +151,12 @@ struct nvme_pt_command {
          */
         struct mtx *            driver_lock;
 };
-#else
-#include <dev/nvme/nvme.h>
-#endif
 
 #define nvme_completion_is_error(cpl)                                   \
         ((cpl)->status.sc != 0 || (cpl)->status.sct != 0)
+#else
+#include <dev/nvme/nvme.h>
+#endif
 
 #define NVME_CTRLR_PREFIX       "/dev/nvme"
 #define NVME_NS_PREFIX          "ns"
