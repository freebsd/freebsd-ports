--- ./bin/auditdistd/subr.c.orig	2014-08-25 09:03:45.000000000 -0400
+++ ./bin/auditdistd/subr.c	2014-08-25 09:05:35.000000000 -0400
@@ -228,6 +228,10 @@
 	PJDLOG_ASSERT(fd != -1);
 
 #ifdef HAVE_KQUEUE
+	if (wait_for_file_kq != -1) {
+		close(wait_for_file_kq);
+		wait_for_file_kq = -1;
+	}
 	kq = kqueue();
 	if (kq == -1) {
 		pjdlog_errno(LOG_WARNING, "kqueue() failed");
