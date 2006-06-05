--- kioslave/audiocd/audiocd.cpp.orig	Fri May 26 21:28:16 2006
+++ kioslave/audiocd/audiocd.cpp	Fri May 26 21:29:42 2006
@@ -213,7 +213,11 @@
 		return 0;
 
 	// Update our knowledge of the disc
+#if defined(Q_OS_LINUX)
 	d->cd.setDevice(drive->ioctl_device_name, 50, false);
+#elif defined(Q_OS_FREEBSD)
+	d->cd.setDevice(drive->cdda_device_name, 50, false);
+#endif
 #if 0
 	// FreeBSD's cdparanoia as of january 5th 2006 has rather broken
 	// support for non-SCSI devices. Although it finds ATA cdroms just
