--- cdda2wav/ioctl.c	Sat Dec 27 17:29:28 2003
+++ cdda2wav/ioctl.c	Sun Jan 18 01:36:36 2004
@@ -59,10 +59,14 @@
 #include <cdrecord.h>
 
 #if defined (HAVE_IOCTL_INTERFACE)
-#if	!defined	sun	&& !defined	__sun
+#if  !defined(sun) && !defined(__sun) && !(__FreeBSD_version >= 501112)
 static struct cdrom_read_audio arg;
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 400014
+static unsigned sector_size = CD_FRAMESIZE;
+#endif
+
 static int err;
 
 static void EnableCdda_cooked __PR((SCSI *scgp, int fAudioMode, unsigned uSectorsize));
@@ -72,13 +76,23 @@
 	int fAudioMode;
 	unsigned uSectorsize;
 {
+#if	defined(__FreeBSD__) && __FreeBSD_version >= 400014
+	if (scgp && scgp->verbose)
+		fprintf(stderr, "EnableCdda_cooked (CDRIOCSETBLOCKSIZE)...\n");
+
+	if (fAudioMode) {
+		if (ioctl(global.cooked_fd, CDRIOCGETBLOCKSIZE, &sector_size) ==-1)
+			sector_size = CD_FRAMESIZE;
+        	ioctl(global.cooked_fd, CDRIOCSETBLOCKSIZE, &uSectorsize);
+	} else
+        	ioctl(global.cooked_fd, CDRIOCSETBLOCKSIZE, &sector_size);
+#elif	defined	CDIOCSETCDDA
 	if (scgp && scgp->verbose) {
 		fprintf(stderr, "EnableCdda_cooked (CDIOCSETCDDA)...\n");
 		if (uSectorsize != CD_FRAMESIZE_RAW)
 			fprintf(stderr, "non audio sector size is ignored.\n");
 	}
 
-#if	defined	CDIOCSETCDDA
 	ioctl(global.cooked_fd, CDIOCSETCDDA, &fAudioMode);
 #else
 	fprintf(stderr, "EnableCdda_cooked (CDIOCSETCDDA) is not available...\n");
@@ -197,6 +211,10 @@
       /* trash the cache */
 
 #if	defined __FreeBSD__
+#if	__FreeBSD_version >= 501112
+      pread(global.cooked_fd, (void *) &p[0], 3*CD_FRAMESIZE_RAW,
+          find_an_off_sector(lSector, SectorBurstVal)*CD_FRAMESIZE_RAW);
+#else
       static struct cdrom_read_audio arg2;
 
       arg2.address.lba = find_an_off_sector(lSector, SectorBurstVal);
@@ -206,6 +224,7 @@
 
       ioctl(global.cooked_fd, CDROMREADAUDIO, &arg2);
 #endif
+#endif
 #if	defined __linux__
       static struct cdrom_read_audio arg2;
 
@@ -267,6 +286,17 @@
 
 /* read 2352 bytes audio data */
 #if	defined __FreeBSD__
+#if	__FreeBSD_version >= 501112
+    if (x && x->verbose) {
+	fprintf(stderr, "ReadCdRom_cooked (pread)...\n");
+    }
+
+  do {
+    err = 0;
+    if (pread(global.cooked_fd, (void *) &p[0], SectorBurstVal*CD_FRAMESIZE_RAW,
+	lSector*CD_FRAMESIZE_RAW) == -1)
+		err = -1;
+#else
   arg.address.lba = lSector;
   arg.addr_format = CDROM_LBA;
   arg.nframes = SectorBurstVal;
@@ -278,6 +308,7 @@
 
   do {
     err = ioctl(global.cooked_fd, CDROMREADAUDIO, &arg);
+#endif
 #endif
 #if	defined __linux__
   arg.addr.lba = lSector;
