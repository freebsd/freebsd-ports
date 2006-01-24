--- src/racoon/plog.c.orig	Fri Dec 30 11:28:03 2005
+++ src/racoon/plog.c	Fri Dec 30 11:28:18 2005
@@ -224,7 +224,7 @@ ploginit()
 		return;
 	}
 
-        openlog(pname, LOG_NDELAY, LOG_DAEMON);
+        openlog(pname, LOG_NDELAY, LOG_SECURITY);
 }
 
 void

