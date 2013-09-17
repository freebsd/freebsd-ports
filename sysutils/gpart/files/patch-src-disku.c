--- ./src/disku.c.orig	2001-02-07 20:04:07.000000000 +0100
+++ ./src/disku.c	2011-03-17 01:15:54.000000000 +0100
@@ -28,7 +28,9 @@
 
 #if defined(__FreeBSD__)
 #include <errno.h>
+#include <sys/param.h>
 #include <sys/disklabel.h>
+#include <sys/disk.h>
 #endif
 
 
@@ -61,12 +63,26 @@
 #endif
 
 #if defined(__FreeBSD__)
-	struct disklabel	dl;
-	if (ioctl(d->d_fd,DIOCGDINFO,&dl) == -1)
-		pr(FATAL,EM_IOCTLFAILED,"DIOCGDINFO",strerror(errno));
-	g.d_c = dl.d_ncylinders;
-	g.d_h = dl.d_ntracks;
-	g.d_s = dl.d_nsectors;
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
+	if (ioctl(d->d_fd, DIOCGSECTORSIZE, &u) == 0)
+		if (u != 512)
+		    pr(FATAL, "sector size not a multiple of 512");
+	if (ioctl(d->d_fd, DIOCGMEDIASIZE, &o))
+		pr(FATAL, EM_IOCTLFAILED, "DIOCGMEDIASIZE", strerror(errno));
+
+	g.d_c = o / u / g.d_h / g.d_s;
 #endif
 
 	return (&g);
