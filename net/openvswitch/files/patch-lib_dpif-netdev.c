--- lib/dpif-netdev.c.orig	2017-11-29 15:46:19 UTC
+++ lib/dpif-netdev.c
@@ -78,6 +78,8 @@
 #include "unixctl.h"
 #include "util.h"
 
+#define	ERRNO_NO_LOCAL_MAPPING	-600
+
 VLOG_DEFINE_THIS_MODULE(dpif_netdev);
 
 #define FLOW_DUMP_MAX_BATCH 50
@@ -4086,7 +4088,11 @@ dpif_netdev_meter_set(struct dpif *dpif,
     /* Validate rates */
     for (i = 0; i < config->n_bands; i++) {
         if (config->bands[i].rate == 0) {
+#ifdef EBADRQC
             return EBADRQC; /* rate must be non-zero */
+#else
+            return ERRNO_NO_LOCAL_MAPPING;
+#endif
         }
     }
 
