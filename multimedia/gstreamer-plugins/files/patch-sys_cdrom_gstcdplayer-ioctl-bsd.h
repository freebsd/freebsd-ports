--- sys/cdrom/gstcdplayer_ioctl_bsd.h.orig	Mon Mar  1 06:52:03 2004
+++ sys/cdrom/gstcdplayer_ioctl_bsd.h	Tue Mar  9 16:05:36 2004
@@ -142,6 +142,7 @@
 {
 	struct ioc_toc_header toc_header;
 	struct ioc_read_toc_entry toc_entry;
+	struct cd_toc_entry toc_entry_data;
 	guint i;
 
 	cd->fd = open(device,O_RDONLY | O_NONBLOCK);
@@ -151,7 +152,7 @@
 	}
 
 	/* get the toc header information */
-	if (ioctl(cd->fd,CDIOREADTOCHDR,&toc_header) != 0) {
+	if (ioctl(cd->fd,CDIOREADTOCHEADER,&toc_header) != 0) {
 		close(cd->fd);
 		cd->fd = -1;
 		return FALSE;
@@ -161,6 +162,8 @@
 	for (i = 1; i <= toc_header.ending_track; i++) {
 		toc_entry.address_format = CD_MSF_FORMAT;
 		toc_entry.starting_track = i;
+		toc_entry.data = &toc_entry_data;
+		toc_entry.data_len = sizeof(toc_entry_data);
 
 		if (ioctl(cd->fd,CDIOREADTOCENTRYS,&toc_entry) != 0) {
 			close(cd->fd);
@@ -168,9 +171,9 @@
 			return FALSE;
 		}
 
-		cd->tracks[i].minute = toc_entry.entry.addr.msf.minute;
-		cd->tracks[i].second = toc_entry.entry.addr.msf.second;
-		cd->tracks[i].frame = toc_entry.entry.addr.msf.frame;
+		cd->tracks[i].minute = toc_entry.data->addr.msf.minute;
+		cd->tracks[i].second = toc_entry.data->addr.msf.second;
+		cd->tracks[i].frame = toc_entry.data->addr.msf.frame;
 		cd->tracks[i].data_track = (toc_entry.data->control & 4) == 4;
 	}
 
@@ -186,9 +189,9 @@
 		return FALSE;
 	}
 
-	cd->tracks[LEADOUT].minute = toc_entry.entry.addr.msf.minute;
-	cd->tracks[LEADOUT].second = toc_entry.entry.addr.msf.second;
-	cd->tracks[LEADOUT].frame = toc_entry.entry.addr.msf.frame;
+	cd->tracks[LEADOUT].minute = toc_entry.data->addr.msf.minute;
+	cd->tracks[LEADOUT].second = toc_entry.data->addr.msf.second;
+	cd->tracks[LEADOUT].frame = toc_entry.data->addr.msf.frame;
 
 	cd->num_tracks = toc_header.ending_track;
 
@@ -224,6 +227,8 @@
 		return FALSE;
 	}
 
+	/* lets return TRUE and lets see what happes (may not be correct)*/
+	return TRUE;
 }
 
 gboolean cd_pause(struct cd *cd)
@@ -321,7 +326,7 @@
 		return -1;
 	}
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 	return sub_channel.data->what.track_info.track_number;
 #else
 	return sub_channel.data->track_number;
