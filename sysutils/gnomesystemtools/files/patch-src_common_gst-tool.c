--- src/common/gst-tool.c.orig	Thu Mar 10 14:39:54 2005
+++ src/common/gst-tool.c	Thu Mar 10 14:40:00 2005
@@ -1653,7 +1653,7 @@ poll_backend (GstTool *tool)
 	struct pollfd fd;
 
 	fd.fd = tool->read_fd;
-	fd.events = POLLIN || POLLPRI;
+	fd.events = POLLIN | POLLPRI;
 
 	while (poll (&fd, 1, 100) <= 0) {
 		while (gtk_events_pending ())
