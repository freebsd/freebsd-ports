--- nautilus-burn-drive.c.orig	Tue Aug 23 11:55:56 2005
+++ nautilus-burn-drive.c	Sat Sep 10 20:32:26 2005
@@ -471,7 +471,6 @@ get_disc_type (const char *dev_path)
 	struct cd_toc_entry              entry;
 	int                              i;
 #endif
-	int                              type;
 #ifndef CDROM_DATA_TRACK
 #define CDROM_DATA_TRACK 4
 #endif
@@ -483,6 +482,10 @@ get_disc_type (const char *dev_path)
 
 	if (ioctl (fd, CDIOREADTOCHEADER, &header) < 0) {
 		close (fd);
+		if (errno == EINVAL)
+			/* If you try to read the TOC header of a blank disc
+			 * on FreeBSD, you get EINVAL. */
+			return CDS_NO_INFO;
 	    	return -1;
 	}
 
@@ -649,7 +652,7 @@ nautilus_burn_drive_get_media_type_from_
 		*is_blank = mmc_profile & 0x10000;
 
 	disc_type = get_disc_type (device);
-	disc_type_get_info (disc_type, is_blank, has_data, has_audio);
+	disc_type_get_info (disc_type, NULL, has_data, has_audio);
 
 	switch (mmc_profile & 0xFFFF) {
 	case -1:
