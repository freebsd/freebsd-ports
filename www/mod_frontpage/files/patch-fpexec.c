--- fpexec.c.orig	Sun Dec  9 23:35:39 2001
+++ fpexec.c	Wed Jan 23 20:10:14 2002
@@ -247,6 +247,11 @@
     cidx++;
 
     for (ep = environ; *ep && cidx < AP_ENVBUF-1; ep++) {
+	if (*ep == NULL) {
+	    log_err("HTTP header mismatch, stop\n");
+	    exit(120);
+	}
+
 	if (!strncmp(*ep, "HTTP_", 5) || !strncmp(*ep,"HTTPS",5)
 	    || !strncmp(*ep,"SSL_",4)) {
 	    cleanenv[cidx] = *ep;
@@ -327,6 +332,11 @@
 	exit(103);
     }
 #endif /*_OSD_POSIX*/
+
+    if (target_uname == NULL) {
+        log_err("invalid target user name: (NULL)\n");
+        exit(105);
+    }
 
     if (!strncmp("~", target_uname, 1)) {
       target_uname++;
