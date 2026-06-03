--- src/ucp/core/ucp_worker.c.orig	2026-02-05 12:41:56 UTC
+++ src/ucp/core/ucp_worker.c
@@ -9,6 +9,8 @@
 #  include "config.h"
 #endif
 
+#include <errno.h>
+
 #include "ucp_am.h"
 #include "ucp_ep_vfs.h"
 #include "ucp_worker.h"
@@ -35,9 +37,15 @@
 #include <ucs/vfs/base/vfs_cb.h>
 #include <ucs/vfs/base/vfs_obj.h>
 #include <sys/poll.h>
-#include <sys/eventfd.h>
-#include <sys/epoll.h>
-#include <sys/timerfd.h>
+#if defined(HAVE_SYS_EVENTFD_H)
+#  include <sys/eventfd.h>
+#endif
+#if defined(HAVE_SYS_TIMERFD_H)
+#  include <sys/timerfd.h>
+#endif
+#if defined(__linux__)
+#  include <sys/epoll.h>
+#endif
 #include <time.h>
 
 
@@ -320,6 +328,7 @@ static ucs_status_t ucp_worker_wakeup_init(ucp_worker_
         worker->flags |= UCP_WORKER_FLAG_EDGE_TRIGGERED;
     }
 
+#if defined(HAVE_SYS_EVENTFD_H)
     worker->eventfd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK);
     if (worker->eventfd == -1) {
         ucs_error("Failed to create event fd: %m");
@@ -328,6 +337,10 @@ static ucs_status_t ucp_worker_wakeup_init(ucp_worker_
     }
 
     ucp_worker_wakeup_ctl_fd(worker, UCP_WORKER_EPFD_OP_ADD, worker->eventfd);
+#else
+    /* No eventfd(). */
+    worker->eventfd = -1;
+#endif
 
     worker->uct_events = 0;
 
@@ -427,6 +440,10 @@ static ucs_status_t ucp_worker_wakeup_signal_fd(ucp_wo
 
     ucs_trace_func("worker=%p fd=%d", worker, worker->eventfd);
 
+    if (worker->eventfd == -1) {
+        return UCS_OK;
+    }
+
     do {
         ret = write(worker->eventfd, &dummy, sizeof(dummy));
         if (ret == sizeof(dummy)) {
@@ -3375,7 +3392,7 @@ void ucp_worker_print_info(ucp_worker_h worker, FILE *
     UCP_WORKER_THREAD_CS_EXIT_CONDITIONAL(worker);
 }
 
-static UCS_F_ALWAYS_INLINE void
+static UCS_F_ALWAYS_INLINE ucs_status_t
 ucp_worker_keepalive_timerfd_init(ucp_worker_h worker)
 {
     ucs_time_t ka_interval = worker->context->config.ext.keepalive_interval;
@@ -3385,14 +3402,18 @@ ucp_worker_keepalive_timerfd_init(ucp_worker_h worker)
 
     if (!(worker->context->config.features & UCP_FEATURE_WAKEUP) ||
         (worker->keepalive.timerfd >= 0)) {
-        return;
+        return UCS_OK;
     }
 
+/* timerfd_* are Linux-only */
+#if !defined(HAVE_SYS_TIMERFD_H)
+    worker->keepalive.timerfd = -1;
+    return UCS_OK;
+#else
     worker->keepalive.timerfd = timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK);
     if (worker->keepalive.timerfd < 0) {
-        ucs_warn("worker %p: failed to create keepalive timer fd: %m",
-                 worker);
-        return;
+        ucs_error("timerfd_create() failed: %m");
+        return UCS_ERR_IO_ERROR;
     }
 
     ucs_assert(ka_interval > 0);
@@ -3412,10 +3433,11 @@ ucp_worker_keepalive_timerfd_init(ucp_worker_h worker)
     ucp_worker_wakeup_ctl_fd(worker, UCP_WORKER_EPFD_OP_ADD,
                              worker->keepalive.timerfd);
 
-    return;
+    return UCS_OK;
 
 err_close_timerfd:
     close(worker->keepalive.timerfd);
+#endif
 }
 
 static UCS_F_ALWAYS_INLINE void
@@ -3571,6 +3593,7 @@ void ucp_worker_keepalive_add_ep(ucp_ep_h ep)
 void ucp_worker_keepalive_add_ep(ucp_ep_h ep)
 {
     ucp_worker_h worker = ep->worker;
+    ucs_status_t status;
 
     if (ucp_ep_config(ep)->key.keepalive_lane == UCP_NULL_LANE) {
         ucs_trace("ep %p flags 0x%x cfg_index %d err_mode %d: keepalive lane"
@@ -3579,7 +3602,12 @@ void ucp_worker_keepalive_add_ep(ucp_ep_h ep)
         return;
     }
 
-    ucp_worker_keepalive_timerfd_init(worker);
+    status = ucp_worker_keepalive_timerfd_init(worker);
+    if ((status != UCS_OK) && (status != UCS_ERR_UNSUPPORTED)) {
+        ucs_warn("worker %p: failed to initialize keepalive timerfd: %s",
+                 worker, ucs_status_string(status));
+    }
+
     ucs_trace("ep %p flags 0x%x: set keepalive lane to %u", ep,
               ep->flags, ucp_ep_config(ep)->key.keepalive_lane);
     uct_worker_progress_register_safe(worker->uct,
