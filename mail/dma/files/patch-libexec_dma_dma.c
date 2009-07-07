--- libexec/dma/dma.c.orig	2009-02-09 01:36:50.000000000 +0100
+++ libexec/dma/dma.c	2009-07-04 00:12:53.000000000 +0200
@@ -612,6 +612,7 @@
 	const char *errmsg = "unknown bounce reason";
 	struct timeval now;
 	struct stat st;
+	struct flock fl;
 
 	syslog(LOG_INFO, "%s: mail from=<%s> to=<%s>",
 	       it->queueid, it->sender, it->addr);
@@ -620,11 +621,27 @@
 	syslog(LOG_INFO, "%s: trying delivery",
 	       it->queueid);
 
+	bzero(&fl, sizeof(fl));
+	fl.l_type = F_WRLCK;
+	fl.l_whence = SEEK_SET;
+	if (fcntl(fileno(it->queuef), F_SETLKW, &fl) == -1) {
+		syslog(LOG_ERR, "%s: failed to lock queue file: %m",
+				it->queueid);
+	}
+
 	if (it->remote)
 		error = deliver_remote(it, &errmsg);
 	else
 		error = deliver_local(it, &errmsg);
 
+	bzero(&fl, sizeof(fl));
+	fl.l_type = F_UNLCK;
+	fl.l_whence = SEEK_SET;
+	if (fcntl(fileno(it->queuef), F_SETLKW, &fl) == -1) {
+		syslog(LOG_ERR, "%s: failed to unlock queue file: %m",
+				it->queueid);
+	}
+
 	switch (error) {
 	case 0:
 		unlink(it->queuefn);
