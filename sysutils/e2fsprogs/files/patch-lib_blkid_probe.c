diff -r 3bd3981defcd -r 3e8071a0e4b0 lib/blkid/probe.c
--- a/lib/blkid/probe.c	Tue May 30 15:47:05 2006 +0200
+++ b/lib/blkid/probe.c	Tue May 30 15:47:12 2006 +0200
@@ -253,7 +253,7 @@ static int probe_fat(struct blkid_probe 
 	struct msdos_super_block *ms = (struct msdos_super_block *) buf;
 	struct vfat_dir_entry *dir;
 	char serno[10];
-	const unsigned char *label = 0, *vol_label = 0;
+	const unsigned char *label = 0, *vol_label = 0, *tmp;
 	unsigned char	*vol_serno;
 	int label_len = 0, maxloop = 100;
 	__u16 sector_size, dir_entries, reserved;
@@ -261,14 +261,17 @@ static int probe_fat(struct blkid_probe 
 	__u32 buf_size, start_data_sect, next, root_start, root_dir_entries;
 
 	/* sector size check */
-	sector_size = blkid_le16(*((__u16 *) &ms->ms_sector_size));
+	tmp = &ms->ms_sector_size;
+	sector_size = tmp[0] + tmp[1] << 8;
 	if (sector_size != 0x200 && sector_size != 0x400 &&
 	    sector_size != 0x800 && sector_size != 0x1000)
 		return 1;
 
-	dir_entries = blkid_le16(*((__u16 *) &ms->ms_dir_entries));
+	tmp = &ms->ms_dir_entries;
+	dir_entries = tmp[0] + tmp[1] << 8;
 	reserved =  blkid_le16(ms->ms_reserved);
-	sect_count = blkid_le16(*((__u16 *) &ms->ms_sectors));
+	tmp = &ms->ms_sectors;
+	sect_count = tmp[0] + tmp[1] << 8;
 	if (sect_count == 0)
 		sect_count = blkid_le32(ms->ms_total_sect);
 
