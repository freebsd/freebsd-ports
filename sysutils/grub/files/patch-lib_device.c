--- lib/device.c.orig	Sat Jan 24 01:52:56 2004
+++ lib/device.c	Sun Jan 25 00:07:02 2004
@@ -78,6 +78,12 @@
 # include <sys/ioctl.h>		/* ioctl */
 # include <sys/disklabel.h>
 # include <sys/cdio.h>		/* CDIOCCLRDEBUG */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#if __FreeBSD_version >= 500040
+#include <sys/disk.h>
+#endif
+#endif
 #endif /* __FreeBSD__ || __NetBSD__ || __OpenBSD__ */
 
 #ifdef HAVE_OPENDISK
@@ -123,6 +129,7 @@
   /* FreeBSD, NetBSD or OpenBSD */
   {
     struct disklabel hdg;
+#if __FreeBSD_version < 500040
     if (ioctl (fd, DIOCGDINFO, &hdg))
       goto fail;
     
@@ -131,6 +138,38 @@
     geom->sectors = hdg.d_nsectors;
     geom->total_sectors = hdg.d_secperunit;
 
+#else
+    u_int    u, secsize;
+    off_t    mediasize;
+
+    if(ioctl(fd, DIOCGSECTORSIZE, &secsize) != 0)
+	secsize = 512;
+
+    if (ioctl(fd, DIOCGMEDIASIZE, &mediasize) != 0)
+	goto fail;
+
+    hdg.d_secperunit = mediasize / secsize;
+
+    if (ioctl(fd, DIOCGFWSECTORS, &u) == 0)
+	    hdg.d_nsectors = u;
+    else
+	    hdg.d_nsectors = 63;
+    if (ioctl(fd, DIOCGFWHEADS, &u) == 0)
+	    hdg.d_ntracks = u;
+    else if (hdg.d_secperunit <= 63*1*1024)
+	    hdg.d_ntracks = 1;
+    else if (hdg.d_secperunit <= 63*16*1024)
+	    hdg.d_ntracks = 16;
+    else
+	    hdg.d_ntracks = 255;
+    hdg.d_secpercyl = hdg.d_ntracks * hdg.d_nsectors;
+    hdg.d_ncylinders = hdg.d_secperunit / hdg.d_secpercyl;
+
+    geom->cylinders = hdg.d_ncylinders;
+    geom->heads = hdg.d_ntracks;
+    geom->sectors = hdg.d_nsectors;
+    geom->total_sectors = hdg.d_secperunit;
+#endif
     close (fd);
     return;
   }
@@ -233,7 +272,7 @@
 #elif defined(__FreeBSD__)
   /* FreeBSD */
 # if __FreeBSD__ >= 4
-  sprintf (name, "/dev/rad%d", unit);
+  sprintf (name, "/dev/ad%d", unit);
 # else /* __FreeBSD__ <= 3 */
   sprintf (name, "/dev/rwd%d", unit);
 # endif /* __FreeBSD__ <= 3 */
@@ -274,7 +313,11 @@
   sprintf (name, "/dev/sd%d", unit);
 #elif defined(__FreeBSD__)
   /* FreeBSD */
+# if __FreeBSD__ >= 4
+  sprintf (name, "/dev/da%d", unit);
+# else /* __FreeBSD__ <= 3 */
   sprintf (name, "/dev/rda%d", unit);
+# endif /* __FreeBSD__ <= 3 */
 #elif defined(__NetBSD__) && defined(HAVE_OPENDISK)
   /* NetBSD */
   char shortname[16];
