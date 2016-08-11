--- lib/efi_loader/efi_disk.c.orig	2016-06-16 04:33:54 UTC
+++ lib/efi_loader/efi_disk.c
@@ -145,11 +145,13 @@ static void efi_disk_add_dev(char *name,
 			     const struct block_drvr *cur_drvr,
 			     const struct blk_desc *desc,
 			     int dev_index,
-			     lbaint_t offset)
+			     disk_partition_t *info,
+			     int logical_partition)
 {
 	struct efi_disk_obj *diskobj;
 	struct efi_device_path_file_path *dp;
 	int objlen = sizeof(*diskobj) + (sizeof(*dp) * 2);
+	static int mediaid = 0;
 
 	diskobj = calloc(1, objlen);
 
@@ -162,14 +164,24 @@ static void efi_disk_add_dev(char *name,
 	diskobj->ops = block_io_disk_template;
 	diskobj->ifname = cur_drvr->name;
 	diskobj->dev_index = dev_index;
-	diskobj->offset = offset;
+	if (info)
+		diskobj->offset = info->start;
 
 	/* Fill in EFI IO Media info (for read/write callbacks) */
 	diskobj->media.removable_media = desc->removable;
 	diskobj->media.media_present = 1;
-	diskobj->media.block_size = desc->blksz;
-	diskobj->media.io_align = desc->blksz;
-	diskobj->media.last_block = desc->lba;
+	diskobj->media.media_id = mediaid++;
+	if (logical_partition) {
+		diskobj->media.logical_partition = 1;
+		diskobj->media.block_size = info->blksz;
+		diskobj->media.io_align = info->blksz;
+		diskobj->media.last_block = info->size - 1;
+	}
+	else {
+		diskobj->media.block_size = desc->blksz;
+		diskobj->media.io_align = desc->blksz;
+		diskobj->media.last_block = desc->lba;
+	}
 	diskobj->ops.media = &diskobj->media;
 
 	/* Fill in device path */
@@ -204,7 +216,7 @@ static int efi_disk_create_eltorito(stru
 	while (!part_get_info(desc, part, &info)) {
 		snprintf(devname, sizeof(devname), "%s%d:%d", cur_drvr->name,
 			 diskid, part);
-		efi_disk_add_dev(devname, cur_drvr, desc, diskid, info.start);
+		efi_disk_add_dev(devname, cur_drvr, desc, diskid, &info, 0);
 		part++;
 		disks++;
 	}
@@ -213,6 +225,30 @@ static int efi_disk_create_eltorito(stru
 	return disks;
 }
 
+static int efi_disk_create_mbr(struct blk_desc *desc,
+				    const struct block_drvr *cur_drvr,
+				    int diskid)
+{
+	int disks = 0;
+	char devname[32] = { 0 }; /* dp->str is u16[32] long */
+	disk_partition_t info;
+	int part = 1;
+
+	if (desc->part_type != PART_TYPE_DOS)
+		return 0;
+
+	while (!part_get_info(desc, part, &info)) {
+		snprintf(devname, sizeof(devname), "%s%d:%d", cur_drvr->name,
+			 diskid, part);
+
+		efi_disk_add_dev(devname, cur_drvr, desc, diskid, &info, 1);
+		part++;
+		disks++;
+	}
+
+	return disks;
+}
+
 /*
  * U-Boot doesn't have a list of all online disk devices. So when running our
  * EFI payload, we scan through all of the potentially available ones and
@@ -241,7 +277,7 @@ int efi_disk_register(void)
 
 			snprintf(devname, sizeof(devname), "%s%d",
 				 cur_drvr->name, i);
-			efi_disk_add_dev(devname, cur_drvr, desc, i, 0);
+			efi_disk_add_dev(devname, cur_drvr, desc, i, NULL, 0);
 			disks++;
 
 			/*
@@ -249,6 +285,7 @@ int efi_disk_register(void)
 			 * in an EFI world, so let's create them here
 			 */
 			disks += efi_disk_create_eltorito(desc, cur_drvr, i);
+			disks += efi_disk_create_mbr(desc, cur_drvr, i);
 		}
 	}
 	printf("Found %d disks\n", disks);
