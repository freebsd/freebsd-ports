--- api/api_storage.c.orig	2019-07-08 19:23:28 UTC
+++ api/api_storage.c
@@ -69,13 +69,6 @@ void dev_stor_init(void)
 	specs[ENUM_SATA].type = DEV_TYP_STOR | DT_STOR_SATA;
 	specs[ENUM_SATA].name = "sata";
 #endif
-#if defined(CONFIG_SCSI)
-	specs[ENUM_SCSI].max_dev = CONFIG_SYS_SCSI_MAX_DEVICE;
-	specs[ENUM_SCSI].enum_started = 0;
-	specs[ENUM_SCSI].enum_ended = 0;
-	specs[ENUM_SCSI].type = DEV_TYP_STOR | DT_STOR_SCSI;
-	specs[ENUM_SCSI].name = "scsi";
-#endif
 #if defined(CONFIG_CMD_USB) && defined(CONFIG_USB_STORAGE)
 	specs[ENUM_USB].max_dev = USB_MAX_STOR_DEV;
 	specs[ENUM_USB].enum_started = 0;
@@ -281,7 +274,7 @@ int dev_enum_storage(struct device_info *di)
 {
 	int i;
 
-	/* check: ide, usb, scsi, mmc */
+	/* check: ide, usb, mmc */
 	for (i = ENUM_IDE; i < ENUM_MAX; i ++) {
 		if (dev_enum_stor(i, di))
 			return 1;
