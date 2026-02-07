--- aoeblk.c.orig	2024-01-03 00:56:10 UTC
+++ aoeblk.c
@@ -114,7 +114,7 @@ aoeblk_ioctl(struct disk *disk, u_long cmd, void *vp, 
 {
 	struct ata_ioc_request *iocmd;
 	struct aoedev *d;
-	int n;
+	int error, n;
 
 	if (cmd != IOCATAREQUEST) {
 		IPRINTK("cmd %ld not IOCATA.\n", cmd);
@@ -153,9 +153,9 @@ aoeblk_ioctl(struct disk *disk, u_long cmd, void *vp, 
 
 	switch (iocmd->ata_ioc_request_ata.command) {
 	case ATA_ATA_IDENTIFY:
-		copyout(d->ad_ident, iocmd->ata_ioc_request_data, sizeof d->ad_ident);
+		error = copyout(d->ad_ident, iocmd->ata_ioc_request_data, sizeof d->ad_ident);
 		mtx_unlock(&d->ad_mtx);
-		return (0);
+		return (error);
 	case ATA_SMART:
 		if (iocmd->ata_ioc_request_ata.feature != ATA_SMART_ATTR_AUTOSAVE) {
 			n = aoecmd_ata_smart(d, iocmd);
