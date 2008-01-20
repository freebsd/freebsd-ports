--- relayctl/relayctl.c.orig	Thu Feb 22 14:59:13 2007
+++ relayctl/relayctl.c	Fri Jun  8 13:00:53 2007
@@ -20,6 +20,7 @@
  */
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/queue.h>
 #include <sys/un.h>
@@ -286,7 +287,7 @@
 	imn = monitor_lookup(imsg->hdr.type);
 	printf("%s: imsg type %u len %u peerid %u pid %d\n", imn->name,
 	    imsg->hdr.type, imsg->hdr.len, imsg->hdr.peerid, imsg->hdr.pid);
-	printf("\ttimestamp: %u, %s", now, ctime(&now));
+	printf("\ttimestamp: %lu, %s", (unsigned long)now, ctime(&now));
 	if (imn->type == -1)
 		done = 1;
 	if (imn->func != NULL)
