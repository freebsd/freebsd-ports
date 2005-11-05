--- src/common/gst-tool.c.orig	Tue Jun 21 15:07:05 2005
+++ src/common/gst-tool.c	Wed Jul  6 01:28:22 2005
@@ -598,7 +598,14 @@ gst_tool_kill_backend_cb (GstDirectiveEn
 		if (tool->root_access == ROOT_ACCESS_SIMULATED_DISABLED)
 			tool->root_access = ROOT_ACCESS_SIMULATED;
 
+#if 0
+		/*
+		 * We do not need to wait for the tool,
+		 * as it will get SIGPIPE anyway.
+		 * This waitpid causes problems on FreeBSD.
+		 */
 		waitpid (tool->backend_pid, NULL, 0);
+#endif
 	}
 }
 
@@ -1655,7 +1662,7 @@ poll_backend (GstTool *tool)
 	struct pollfd fd;
 
 	fd.fd = tool->read_fd;
-	fd.events = POLLIN || POLLPRI;
+	fd.events = POLLIN | POLLPRI;
 
 	while (poll (&fd, 1, 100) <= 0) {
 		while (gtk_events_pending ())
