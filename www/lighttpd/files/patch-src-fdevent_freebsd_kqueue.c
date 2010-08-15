Index: src/fdevent_freebsd_kqueue.c
===================================================================
--- src/fdevent_freebsd_kqueue.c	(revision 2763)
+++ src/fdevent_freebsd_kqueue.c	(revision 2764)
@@ -39,12 +39,15 @@
 		NULL, 0,
 		&ts);
 
+	/* Ignore errors for now, as we remove for READ and WRITE without knowing what was registered */
+#if 0
 	if (ret == -1) {
 		log_error_write(ev->srv, __FILE__, __LINE__, "SS",
 			"kqueue event delete failed: ", strerror(errno));
 
 		return -1;
 	}
+#endif
 
 	return -1;
 }
