--- ufs_copy.c.orig	Sun Nov 20 19:57:13 2005
+++ ufs_copy.c	Sun Nov 20 20:04:12 2005
@@ -504,7 +504,11 @@
 			err(1, "malloc failed");
 		cb->aio_sigevent.sigev_notify = SIGEV_KEVENT;
 		cb->aio_sigevent.sigev_notify_kqueue = kq;
+#if __FreeBSD_version >= 700005
+		cb->aio_sigevent.sigev_value.sival_ptr = ac;
+#else
 		cb->aio_sigevent.sigev_value.sigval_ptr = ac;
+#endif
 		ac->status = AC_FREE;
 	}
 	last_free = 0;
