--- lib/device.c.orig	Sat Oct 13 00:20:05 2001
+++ lib/device.c	Sun Mar 24 10:31:41 2002
@@ -209,7 +209,7 @@
 #elif defined(__FreeBSD__)
   /* FreeBSD */
 # if __FreeBSD__ >= 4
-  sprintf (name, "/dev/rad%d", unit);
+  sprintf (name, "/dev/ad%d", unit);
 # else /* __FreeBSD__ <= 3 */
   sprintf (name, "/dev/rwd%d", unit);
 # endif /* __FreeBSD__ <= 3 */
@@ -245,7 +245,7 @@
   sprintf (name, "/dev/sd%d", unit);
 #elif defined(__FreeBSD__)
   /* FreeBSD */
-  sprintf (name, "/dev/rda%d", unit);
+  sprintf (name, "/dev/da%d", unit);
 #elif defined(__NetBSD__) && defined(HAVE_OPENDISK)
   /* NetBSD */
   char shortname[16];
