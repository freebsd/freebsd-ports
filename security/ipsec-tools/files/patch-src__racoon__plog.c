--- ./src/racoon/plog.c.orig	Wed Dec  7 18:19:51 2005
+++ ./src/racoon/plog.c	Wed Jun  6 00:49:18 2007
@@ -224,7 +224,7 @@
 		return;
 	}
 
-        openlog(pname, LOG_NDELAY, LOG_DAEMON);
+        openlog(pname, LOG_NDELAY, LOG_SECURITY);
 }
 
 void
