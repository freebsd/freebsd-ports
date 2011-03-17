--- ./src/disku.c.orig	2001-02-07 20:04:07.000000000 +0100
+++ ./src/disku.c	2011-03-17 01:15:54.000000000 +0100
@@ -28,7 +28,11 @@
 
 #if defined(__FreeBSD__)
 #include <errno.h>
+#include <sys/param.h>
 #include <sys/disklabel.h>
+#if __FreeBSD_version >= 500040
+#include <sys/disk.h>
+#endif
 #endif
 
 
@@ -61,12 +65,45 @@
 #endif
 
 #if defined(__FreeBSD__)
+#if __FreeBSD_version < 500040
 	struct disklabel	dl;
 	if (ioctl(d->d_fd,DIOCGDINFO,&dl) == -1)
 		pr(FATAL,EM_IOCTLFAILED,"DIOCGDINFO",strerror(errno));
 	g.d_c = dl.d_ncylinders;
 	g.d_h = dl.d_ntracks;
 	g.d_s = dl.d_nsectors;
+#else
+	struct disklabel	loclab;
+	u_int    u;
+	off_t	 o; /* total disk size */
+
+	if (ioctl(d->d_fd, DIOCGFWSECTORS, &u) == 0)
+		g.d_s = u;
+	else
+		pr(FATAL, EM_IOCTLFAILED, "DIOCGFWSECTORS", strerror(errno));
+		// loclab.d_nsectors = 63;
+	if (ioctl(d->d_fd, DIOCGFWHEADS, &u) == 0)
+		g.d_h = u;
+	else
+		pr(FATAL, EM_IOCTLFAILED, "DIOCGFWHEADS", strerror(errno));
+#if 0
+	else if (loclab.d_secperunit <= 63*1*1024)
+		loclab.d_ntracks = 1;
+	else if (loclab.d_secperunit <= 63*16*1024)
+		loclab.d_ntracks = 16;
+	else
+		loclab.d_ntracks = 255;
+#endif
+	if (ioctl(d->d_fd, DIOCGSECTORSIZE, &u) == 0)
+		if (u != 512)
+		    pr(FATAL, "sector size not a multiple of 512");
+	if (ioctl(d->d_fd, DIOCGMEDIASIZE, &o))
+		pr(FATAL, EM_IOCTLFAILED, "DIOCGMEDIASIZE", strerror(errno));
+	loclab.d_secpercyl = loclab.d_ntracks * loclab.d_nsectors;
+	loclab.d_ncylinders = loclab.d_secperunit / loclab.d_secpercyl;
+
+	g.d_c = o / u / g.d_h / g.d_s; // loclab.d_ncylinders;
+#endif
 #endif
 
 	return (&g);
