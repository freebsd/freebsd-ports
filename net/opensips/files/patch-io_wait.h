--- io_wait.h.orig	2015-05-07 14:13:54 UTC
+++ io_wait.h
@@ -56,6 +56,7 @@
 
 #include <errno.h>
 #include <string.h>
+#include "ip_addr.h"
 #ifdef HAVE_SIGIO_RT
 #define __USE_GNU /* or else F_SETSIG won't be included */
 #define _GNU_SOURCE /* define this as well */
@@ -348,19 +349,21 @@ inline static int io_watch_add(	io_wait_
 		goto error;
 	}
 	if (prio > h->max_prio) {
-		LM_BUG("[%s] priority %d requested (max is %d)\n",
+		LM_DBG("[%s] priority %d requested (max is %d)\n",
 			h->name, prio, h->max_prio);
 		goto error;
 	}
+#ifdef HAVE_EPOLL
 	LM_DBG("[%s] io_watch_add op (%d on %d) (%p, %d, %d, %p,%d), fd_no=%d/%d\n",
 			h->name,fd,h->epfd, h,fd,type,data,flags,h->fd_no,h->max_fd_no);
+#endif
 	//fd_array_print;
 	/*  hash sanity check */
 	e=get_fd_map(h, fd);
 
 	if (e->flags & flags){
 		if (e->data != data) {
-			LM_BUG("[%s] BUG trying to overwrite entry %d"
+			LM_DBG("[%s] BUG trying to overwrite entry %d"
 					" in the hash(%d, %d, %p,%d) with (%d, %d, %p,%d)\n",
 					h->name,fd, e->fd, e->type, e->data,e->flags, fd, type, data,flags);
 			goto error;
