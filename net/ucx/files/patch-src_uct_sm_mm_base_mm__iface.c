--- src/uct/sm/mm/base/mm_iface.c.orig	2026-03-14 22:02:10 UTC
+++ src/uct/sm/mm/base/mm_iface.c
@@ -19,6 +19,9 @@
 #include <ucs/async/async.h>
 #include <ucs/sys/string.h>
 #include <sys/poll.h>
+#include <sys/un.h>
+#include <stddef.h>
+#include <unistd.h>
 
 
 /* Maximal number of events to clear from the signaling pipe in single call */
@@ -681,6 +684,10 @@ static ucs_status_t uct_mm_iface_create_signal_fd(uct_
     ucs_status_t status;
     socklen_t addrlen;
     struct sockaddr_un bind_addr;
+#if defined(__FreeBSD__)
+    const char *tmpdir;
+    int path_len;
+#endif
     int ret;
 
     /* Create a UNIX domain socket to send and receive wakeup signal from remote processes */
@@ -700,10 +707,33 @@ static ucs_status_t uct_mm_iface_create_signal_fd(uct_
     /* Bind the signal socket to automatic address */
     bind_addr.sun_family = AF_UNIX;
     memset(bind_addr.sun_path, 0, sizeof(bind_addr.sun_path));
+#if defined(__FreeBSD__)
+    tmpdir = ucs_get_tmpdir();
+    path_len = snprintf(bind_addr.sun_path, sizeof(bind_addr.sun_path),
+                        "%s/ucx_mm.%ld.%p",
+                        tmpdir, (long)getpid(), (void*)iface);
+    if ((path_len < 0) || ((size_t)path_len >= sizeof(bind_addr.sun_path))) {
+        ucs_error("Failed to generate unix domain socket path");
+        status = UCS_ERR_IO_ERROR;
+        goto err_close;
+    }
+
+    unlink(bind_addr.sun_path);
+
+    addrlen = offsetof(struct sockaddr_un, sun_path) + path_len + 1;
+    ret = bind(iface->signal_fd, (struct sockaddr*)&bind_addr, addrlen);
+#else
+    /* Linux autobind behavior */
     ret = bind(iface->signal_fd, (struct sockaddr*)&bind_addr, sizeof(sa_family_t));
+#endif
     if (ret < 0) {
         ucs_error("Failed to auto-bind unix domain socket: %m");
         status = UCS_ERR_IO_ERROR;
+#if defined(__FreeBSD__)
+        if (bind_addr.sun_path[0] != '\0') {
+            unlink(bind_addr.sun_path);
+        }
+#endif
         goto err_close;
     }
 
@@ -718,6 +748,11 @@ static ucs_status_t uct_mm_iface_create_signal_fd(uct_
     if (ret < 0) {
         ucs_error("Failed to retrieve unix domain socket address: %m");
         status = UCS_ERR_IO_ERROR;
+#if defined(__FreeBSD__)
+        if (bind_addr.sun_path[0] != '\0') {
+            unlink(bind_addr.sun_path);
+        }
+#endif
         goto err_close;
     }
 
@@ -904,6 +939,17 @@ static UCS_CLASS_CLEANUP_FUNC(uct_mm_iface_t)
 
     ucs_mpool_put(self->last_recv_desc);
     ucs_mpool_cleanup(&self->recv_desc_mp, 1);
+
+#if defined(__FreeBSD__)
+    {
+        const struct sockaddr_un *sun =
+            (const struct sockaddr_un *)ucs_unaligned_ptr(&self->recv_fifo_ctl->signal_sockaddr);
+        if ((self->recv_fifo_ctl->signal_addrlen > offsetof(struct sockaddr_un, sun_path)) &&
+            (sun->sun_path[0] != '\0')) {
+            unlink(sun->sun_path);
+        }
+    }
+#endif
     close(self->signal_fd);
     uct_iface_mem_free(&self->recv_fifo_mem);
     ucs_arbiter_cleanup(&self->arbiter);
