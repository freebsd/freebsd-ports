--- platform/FreeBSD/sm_io.c.orig	Mon Jul 25 12:08:47 2005
+++ platform/FreeBSD/sm_io.c	Mon Jul 25 12:12:27 2005
@@ -81,7 +81,7 @@
 void
 gets_io()
 {
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
     io_numdevs = devstat_getnumdevs(NULL);
 #else
     io_numdevs = getnumdevs();
@@ -98,7 +98,7 @@
     /* clear the devinfo struct, as getdevs expects it to be all zeroes */
     bzero(io_stats.dinfo, sizeof(struct devinfo));
 
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
     devstat_getdevs(NULL, &io_stats);
 #else
     getdevs(&io_stats);
@@ -118,7 +118,7 @@
 	    strlen(ds->device_name) < strlen(dev) &&
 	    isdigit(dev[strlen(ds->device_name)]) &&
 	    atoi(&dev[strlen(ds->device_name)]) == ds->unit_number) {
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
 	    return snpack(symon_buf, maxlen, dev, MT_IO2,
 			  ds->operations[DEVSTAT_READ],
 			  ds->operations[DEVSTAT_WRITE],
