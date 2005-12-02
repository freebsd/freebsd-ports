--- platform/FreeBSD/sm_io.c.orig	Sat Nov 12 20:16:41 2005
+++ platform/FreeBSD/sm_io.c	Sat Nov 12 20:17:10 2005
@@ -80,7 +80,7 @@
 void
 gets_io()
 {
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
     io_numdevs = devstat_getnumdevs(NULL);
 #else
     io_numdevs = getnumdevs();
@@ -97,7 +97,7 @@
     /* clear the devinfo struct, as getdevs expects it to be all zeroes */
     bzero(io_stats.dinfo, sizeof(struct devinfo));
 
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
     devstat_getdevs(NULL, &io_stats);
 #else
     getdevs(&io_stats);
@@ -117,7 +117,7 @@
 	    strlen(ds->device_name) < strlen(st->arg) &&
 	    isdigit(st->arg[strlen(ds->device_name)]) &&
 	    atoi(&st->arg[strlen(ds->device_name)]) == ds->unit_number) {
-#if DEVSTAT_USER_API_VER == 5
+#if DEVSTAT_USER_API_VER == 5 || DEVSTAT_USER_API_VER == 6
 	    return snpack(symon_buf, maxlen, st->arg, MT_IO2,
 			  ds->operations[DEVSTAT_READ],
 			  ds->operations[DEVSTAT_WRITE],
