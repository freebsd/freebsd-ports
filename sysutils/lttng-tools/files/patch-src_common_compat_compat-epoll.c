--- src/common/compat/compat-epoll.c.orig	2017-01-13 22:20:45 UTC
+++ src/common/compat/compat-epoll.c
@@ -31,7 +31,11 @@
 
 #include "poll.h"
 
-unsigned int poll_max_size;
+unsigned int poll_max_size
+#if defined(__FreeBSD__)
+= DEFAULT_POLL_SIZE
+#endif
+;
 
 /*
  * Resize the epoll events structure of the new size.
@@ -258,6 +262,7 @@ int compat_epoll_set_max_size(void)
 	ssize_t size_ret;
 	char buf[64];
 
+#if !defined(__FreeBSD__)
 	fd = open(COMPAT_EPOLL_PROC_PATH, O_RDONLY);
 	if (fd < 0) {
 		retval = -1;
@@ -282,8 +287,10 @@ end_read:
 		PERROR("close");
 	}
 end:
+#endif
 	if (!poll_max_size) {
 		poll_max_size = DEFAULT_POLL_SIZE;
+		retval = 0;
 	}
 	DBG("epoll set max size is %d", poll_max_size);
 	return retval;
