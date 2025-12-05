--- camcontrol.c.orig	2025-07-31 07:59:58 UTC
+++ camcontrol.c
@@ -266,6 +266,9 @@ static void stopUnit(struct cam_device *cam_dev)
                     /* start/stop */ 0,
                     /* load_eject */ 0,
                     /* immediate */ 0,
+#if __FreeBSD_version >= 1600004
+                    /* power_condition */ SSS_PC_START_VALID,
+#endif
                     /* sense_len */ SSD_FULL_SIZE,
                     /* timeout */ 30000);
 
