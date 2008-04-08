--- relayctl/relayctl.c.orig	2007-12-20 21:15:43.000000000 +0100
+++ relayctl/relayctl.c	2008-03-20 17:15:14.000000000 +0100
@@ -20,6 +20,7 @@
  */
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/queue.h>
 #include <sys/un.h>
@@ -297,7 +298,7 @@
 	imn = monitor_lookup(imsg->hdr.type);
 	printf("%s: imsg type %u len %u peerid %u pid %d\n", imn->name,
 	    imsg->hdr.type, imsg->hdr.len, imsg->hdr.peerid, imsg->hdr.pid);
-	printf("\ttimestamp: %u, %s", now, ctime(&now));
+	printf("\ttimestamp: %lu, %s", (unsigned long)now, ctime(&now));
 	if (imn->type == -1)
 		done = 1;
 	if (imn->func != NULL)
@@ -508,7 +509,7 @@
 	printf("\t%8s\ttotal: %llu sessions\n"
 	    "\t%8s\tlast: %u/%us %u/h %u/d sessions\n"
 	    "\t%8s\taverage: %u/%us %u/h %u/d sessions\n",
-	    "", crs.cnt,
+	    "", (long long unsigned)crs.cnt,
 	    "", crs.last, crs.interval,
 	    crs.last_hour, crs.last_day,
 	    "", crs.avg, crs.interval,
