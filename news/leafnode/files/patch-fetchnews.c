--- fetchnews.c	Fri Sep  3 01:39:44 2004
+++ fetchnews.c.new	Fri Sep  3 01:37:56 2004
@@ -2225,6 +2225,7 @@
     volatile int rc = 0, skip_servers = 0;
     volatile int anypost = 0, waitchild = 0, quiet;
     struct server *current_server;
+    volatile int need_refetch = 0;
 
     int option, reply;
     pid_t pid;
@@ -2380,8 +2381,10 @@
 	    nntpquit();
 	    if (!rc)
 		rc = 2;
-	    if (forceactive)
+	    if (forceactive) {
 		error_refetch("caught signal that caused a premature abort.");
+		need_refetch = 1;
+	    }
 	    skip_servers = 1;	/* in this case, jump the while ... loop */
 	} else {
 	    canjump = 1;
@@ -2458,8 +2461,10 @@
 		    /* get list of newsgroups or new newsgroups */
 		    if (current_server->updateactive) {
 			if (nntpactive(current_server, &stamp)) {
-			    if (forceactive)
+			    if (forceactive) {
 				error_refetch("obtaining the active file failed.");
+				need_refetch = 1;
+			    }
 			    rc = 1;
 			}
 		    } else {
@@ -2477,8 +2482,10 @@
 	} else { /* reply = nntpconnect */
 	    if (verbose)
 		printf("%s: connection failed.\n", current_server->name);
-	    if (forceactive)
+	    if (forceactive && current_server->updateactive) {
 		error_refetch("fetching the active list from a server failed.");
+		need_refetch = 1;
+	    }
 	    rc = 2;
 	}
 	if (!usesupplement)
@@ -2545,7 +2552,7 @@
 		    rc = 1;
 		}
 	    } else {
-		if (rc == 0 && updateactive())
+		if (need_refetch == 0 && updateactive())
 		    if (killactiveread()) {
 			error_refetch("cannot update active.read file.");
 			rc = 1;
