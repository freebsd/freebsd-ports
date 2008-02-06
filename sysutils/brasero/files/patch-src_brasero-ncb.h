--- src/brasero-ncb.h.orig	2008-01-02 15:01:39.000000000 -0500
+++ src/brasero-ncb.h	2008-01-02 15:02:15.000000000 -0500
@@ -42,6 +42,9 @@ nautilus_burn_drive_get_drive_type ((dri
 #define NCB_DRIVE_GET_DEVICE(drive) 	\
 nautilus_burn_drive_get_device (drive)
 
+#define NCB_DRIVE_GET_CRECORD_DEVICE(drive)	\
+nautilus_burn_drive_get_cdrecord_device (drive)
+
 #define NCB_DRIVE_GET_LIST(list, recorders, image)	\
 {	\
 	NautilusBurnDriveMonitor *monitor;	\
