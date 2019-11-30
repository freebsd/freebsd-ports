--- uhidd/uhidd_cuse4bsd.c.orig	2012-10-14 19:53:44 UTC
+++ uhidd/uhidd_cuse4bsd.c
@@ -29,7 +29,7 @@ __FBSDID("$FreeBSD$");
 
 #include <sys/param.h>
 #include <sys/wait.h>
-#include <cuse4bsd.h>
+#include <cuse.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
@@ -70,16 +70,16 @@ ucuse_init_again:
 		} else {
 			if (verbose)
 				syslog(LOG_INFO, "Attempt to load kernel"
-				    " module cuse4bsd.ko...");
-			status = system("kldload cuse4bsd");
+				    " module cuse.ko...");
+			status = system("kldload cuse");
 			if (WEXITSTATUS(status) != 0) {
-				syslog(LOG_ERR, "Failed to load cuse4bsd"
+				syslog(LOG_ERR, "Failed to load cuse"
 				    " kernel module");
 				return (-1);
 			}
 			if (verbose)
 				syslog(LOG_INFO, "Successfully loaded"
-				    " cuse4bsd kernel module");
+				    " cuse kernel module");
 			cuse4bsd_load = 1;
 			goto ucuse_init_again;
 		}
@@ -88,7 +88,7 @@ ucuse_init_again:
 	cuse4bsd_init = 1;
 
 	if (verbose)
-		syslog(LOG_INFO, "cuse4bsd initiailzed.");
+		syslog(LOG_INFO, "cuse initiailzed.");
 
 	return (0);
 }
