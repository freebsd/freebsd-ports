--- lib/efi_loader/efi_disk.c.orig	2016-11-14 16:27:11 UTC
+++ lib/efi_loader/efi_disk.c
@@ -197,11 +197,13 @@ static void efi_disk_add_dev(const char 
 			     const char *if_typename,
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
 
 	/* Don't add empty devices */
 	if (!desc->lba)
@@ -218,16 +220,28 @@ static void efi_disk_add_dev(const char 
 	diskobj->ops = block_io_disk_template;
 	diskobj->ifname = if_typename;
 	diskobj->dev_index = dev_index;
-	diskobj->offset = offset;
+	if (info)
+	  diskobj->offset = info->start;
+
 	diskobj->desc = desc;
 
 	/* Fill in EFI IO Media info (for read/write callbacks) */
 	diskobj->media.removable_media = desc->removable;
 	diskobj->media.media_present = 1;
-	diskobj->media.block_size = desc->blksz;
-	diskobj->media.io_align = desc->blksz;
-	diskobj->media.last_block = desc->lba - offset;
+	diskobj->media.media_id = mediaid++;
 	diskobj->ops.media = &diskobj->media;
+	if (logical_partition) {
+		printf("Adding logical partition\n");
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
 
 	/* Fill in device path */
 	dp = (void*)&diskobj[1];
@@ -262,8 +276,7 @@ static int efi_disk_create_eltorito(stru
 	while (!part_get_info(desc, part, &info)) {
 		snprintf(devname, sizeof(devname), "%s:%d", pdevname,
 			 part);
-		efi_disk_add_dev(devname, if_typename, desc, diskid,
-				 info.start);
+		efi_disk_add_dev(devname, if_typename, desc, diskid, 0, 0);
 		part++;
 		disks++;
 	}
@@ -272,6 +285,30 @@ static int efi_disk_create_eltorito(stru
 	return disks;
 }
 
+static int efi_disk_create_mbr(struct blk_desc *desc,
+				    const struct blk_driver *cur_drvr,
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
+		snprintf(devname, sizeof(devname), "%s%d:%d", cur_drvr->if_typename,
+			 diskid, part);
+
+		efi_disk_add_dev(devname, cur_drvr->if_typename, desc, diskid, &info, 1);
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
@@ -296,13 +333,14 @@ int efi_disk_register(void)
 		const char *if_typename = dev->driver->name;
 
 		printf("Scanning disk %s...\n", dev->name);
-		efi_disk_add_dev(dev->name, if_typename, desc, desc->devnum, 0);
+		efi_disk_add_dev(dev->name, if_typename, desc, desc->devnum, NULL, 0);
 		disks++;
 
 		/*
 		* El Torito images show up as block devices in an EFI world,
 		* so let's create them here
 		*/
+		disks += efi_disk_create_mbr(desc, dev, desc->devnum);
 		disks += efi_disk_create_eltorito(desc, if_typename,
 						  desc->devnum, dev->name);
 	}
@@ -332,15 +370,17 @@ int efi_disk_register(void)
 
 			snprintf(devname, sizeof(devname), "%s%d",
 				 if_typename, i);
-			efi_disk_add_dev(devname, if_typename, desc, i, 0);
+			efi_disk_add_dev(devname, if_typename, desc, i, 0, 0);
 			disks++;
 
 			/*
 			 * El Torito images show up as block devices
 			 * in an EFI world, so let's create them here
 			 */
+			disks += efi_disk_create_mbr(desc, cur_drvr, i);
 			disks += efi_disk_create_eltorito(desc, if_typename,
 							  i, devname);
+
 		}
 	}
 #endif
