--- Xext/shm.c.orig	2016-07-19 17:14:21 UTC
+++ Xext/shm.c
@@ -1210,7 +1210,11 @@ shm_tmpfile(void)
 	}
 	ErrorF ("Not using O_TMPFILE\n");
 #endif
+#ifdef HAVE_MKOSTEMP
+	fd = mkostemp(template, O_CLOEXEC);
+#else
 	fd = mkstemp(template);
+#endif
 	if (fd < 0)
 		return -1;
 	unlink(template);
