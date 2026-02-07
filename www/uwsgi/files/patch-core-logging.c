--- core/logging.c.orig	2020-11-06 10:12:49.865752000 +0100
+++ core/logging.c	2020-11-06 10:17:57.825745000 +0100
@@ -536,13 +536,23 @@
 			uwsgi_error_open(logfile);
 			exit(1);
 		}
-		else {
-			if (dup2(fd, log_fd) < 0) {
-				// this could be lost :(
-				uwsgi_error("uwsgi_log_do_rotate()/dup2()");
-				exit(1);
-			}
+		if (dup2(fd, log_fd) < 0) {
+			// this could be lost :(
+			uwsgi_error("uwsgi_log_do_rotate()/dup2()");
 			close(fd);
+			exit(1);
+		}
+		close(fd);
+
+		if (uwsgi.chmod_logfile_value) {
+			if (fchmod(log_fd, uwsgi.chmod_logfile_value)) {
+				uwsgi_error("fchmod()");
+			}
+		}
+		if (uwsgi.logfile_chown) {
+			if (fchown(log_fd, uwsgi.uid, uwsgi.gid)) {
+				uwsgi_error("fchown()");
+			}
 		}
 	}
 	else {
