--- src/ucs/sys/event_set.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/sys/event_set.c
@@ -19,9 +19,14 @@
 #include <string.h>
 #include <errno.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#else
 #include <sys/epoll.h>
+#endif
 
-
 enum {
     UCS_SYS_EVENT_SET_EXTERNAL_EVENT_FD = UCS_BIT(0),
 };
@@ -32,9 +37,46 @@ const unsigned ucs_sys_event_set_max_wait_events =
 };
 
 const unsigned ucs_sys_event_set_max_wait_events =
+#if defined(__FreeBSD__)
+    UCS_ALLOCA_MAX_SIZE / sizeof(struct kevent);
+#else
     UCS_ALLOCA_MAX_SIZE / sizeof(struct epoll_event);
+#endif
 
 
+#if defined(__FreeBSD__)
+static inline int ucs_event_set_map_to_raw_flags(ucs_event_set_types_t events)
+{
+    /* Approximate edge-triggered behavior with EV_CLEAR */
+    return (events & UCS_EVENT_SET_EDGE_TRIGGERED) ? EV_CLEAR : 0;
+}
+
+static inline int ucs_event_set_map_to_events(const struct kevent *kev)
+{
+    ucs_event_set_types_t events = 0;
+
+    if (kev->filter == EVFILT_READ) {
+        events |= UCS_EVENT_SET_EVREAD;
+    } else if (kev->filter == EVFILT_WRITE) {
+        events |= UCS_EVENT_SET_EVWRITE;
+    }
+    if (kev->flags & EV_ERROR) {
+        events |= UCS_EVENT_SET_EVERR;
+    }
+    return events;
+}
+
+static int ucs_kqueue_ctl(int kq, int fd, int filter, int op_flags,
+                          int fflags, intptr_t data, void *udata)
+{
+    struct kevent kev;
+    EV_SET(&kev, (uintptr_t)fd, filter, op_flags, fflags, data, udata);
+    if (kevent(kq, &kev, 1, NULL, 0, NULL) < 0) {
+        return -1;
+    }
+    return 0;
+}
+#else
 static inline int ucs_event_set_map_to_raw_events(ucs_event_set_types_t events)
 {
     int raw_events = 0;
@@ -72,6 +114,7 @@ static inline int ucs_event_set_map_to_events(int raw_
     }
     return events;
 }
+#endif
 
 static ucs_sys_event_set_t *ucs_event_set_alloc(int event_fd, unsigned flags)
 {
@@ -105,12 +148,21 @@ ucs_status_t ucs_event_set_create(ucs_sys_event_set_t 
     ucs_status_t status;
     int event_fd;
 
+#if defined(__FreeBSD__)
+    /* Create kqueue set the thread will wait on */
+    event_fd = kqueue();
+    if (event_fd < 0) {
+        ucs_error("kqueue() failed: %m");
+        return UCS_ERR_IO_ERROR;
+    }
+#else
     /* Create epoll set the thread will wait on */
     event_fd = epoll_create(1);
     if (event_fd < 0) {
         ucs_error("epoll_create() failed: %m");
         return UCS_ERR_IO_ERROR;
     }
+#endif
 
     *event_set_p = ucs_event_set_alloc(event_fd, 0);
     if (*event_set_p == NULL) {
@@ -129,6 +181,26 @@ ucs_status_t ucs_event_set_add(ucs_sys_event_set_t *ev
                                ucs_event_set_types_t events,
                                void *callback_data)
 {
+#if defined(__FreeBSD__)
+    int kq = event_set->event_fd;
+    int raw_flags = ucs_event_set_map_to_raw_flags(events);
+
+    if (events & UCS_EVENT_SET_EVREAD) {
+        if (ucs_kqueue_ctl(kq, fd, EVFILT_READ, EV_ADD | EV_ENABLE | raw_flags,
+                           0, 0, callback_data) < 0) {
+            ucs_error("kevent(kq=%d, ADD, fd=%d, READ) failed: %m", kq, fd);
+            return UCS_ERR_IO_ERROR;
+        }
+    }
+    if (events & UCS_EVENT_SET_EVWRITE) {
+        if (ucs_kqueue_ctl(kq, fd, EVFILT_WRITE, EV_ADD | EV_ENABLE | raw_flags,
+                           0, 0, callback_data) < 0) {
+            ucs_error("kevent(kq=%d, ADD, fd=%d, WRITE) failed: %m", kq, fd);
+            return UCS_ERR_IO_ERROR;
+        }
+    }
+    return UCS_OK;
+#else
     struct epoll_event raw_event;
     int ret;
 
@@ -144,12 +216,18 @@ ucs_status_t ucs_event_set_add(ucs_sys_event_set_t *ev
     }
 
     return UCS_OK;
+#endif
 }
 
 ucs_status_t ucs_event_set_mod(ucs_sys_event_set_t *event_set, int fd,
                                ucs_event_set_types_t events,
                                void *callback_data)
 {
+#if defined(__FreeBSD__)
+    /* Simplest: delete then re-add with new mask */
+    (void)ucs_event_set_del(event_set, fd);
+    return ucs_event_set_add(event_set, fd, events, callback_data);
+#else
     struct epoll_event raw_event;
     int ret;
 
@@ -165,10 +243,28 @@ ucs_status_t ucs_event_set_mod(ucs_sys_event_set_t *ev
     }
 
     return UCS_OK;
+#endif
 }
 
 ucs_status_t ucs_event_set_del(ucs_sys_event_set_t *event_set, int fd)
 {
+#if defined(__FreeBSD__)
+    int kq = event_set->event_fd;
+    int ret = 0;
+
+    /* Delete both filters; ignore ENOENT (not registered). */
+    if ((ucs_kqueue_ctl(kq, fd, EVFILT_READ, EV_DELETE, 0, 0, NULL) < 0) &&
+        (errno != ENOENT)) {
+        ucs_error("kevent(kq=%d, DEL, fd=%d, READ) failed: %m", kq, fd);
+        ret = -1;
+    }
+    if ((ucs_kqueue_ctl(kq, fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL) < 0) &&
+        (errno != ENOENT)) {
+        ucs_error("kevent(kq=%d, DEL, fd=%d, WRITE) failed: %m", kq, fd);
+        ret = -1;
+    }
+    return (ret < 0) ? UCS_ERR_IO_ERROR : UCS_OK;
+#else
     int ret;
 
     ret = epoll_ctl(event_set->event_fd, EPOLL_CTL_DEL, fd, NULL);
@@ -179,6 +275,7 @@ ucs_status_t ucs_event_set_del(ucs_sys_event_set_t *ev
     }
 
     return UCS_OK;
+#endif
 }
 
 ucs_status_t ucs_event_set_wait(ucs_sys_event_set_t *event_set,
@@ -186,6 +283,45 @@ ucs_status_t ucs_event_set_wait(ucs_sys_event_set_t *e
                                 ucs_event_set_handler_t event_set_handler,
                                 void *arg)
 {
+#if defined(__FreeBSD__)
+    struct kevent *events;
+    int nready, i, io_events;
+    struct timespec ts, *tsp;
+
+    ucs_assert(event_set_handler != NULL);
+    ucs_assert(num_events != NULL);
+    ucs_assert(*num_events <= ucs_sys_event_set_max_wait_events);
+
+    events = ucs_alloca(sizeof(*events) * *num_events);
+
+    if (timeout_ms < 0) {
+        tsp = NULL;
+    } else {
+        ts.tv_sec  = timeout_ms / 1000;
+        ts.tv_nsec = (timeout_ms % 1000) * 1000000;
+        tsp = &ts;
+    }
+
+    nready = kevent(event_set->event_fd, NULL, 0, events, *num_events, tsp);
+    if (ucs_unlikely(nready < 0)) {
+        *num_events = 0;
+        if (errno == EINTR) {
+            return UCS_INPROGRESS;
+        }
+        ucs_error("kevent() failed: %m");
+        return UCS_ERR_IO_ERROR;
+    }
+
+    ucs_assert(nready <= *num_events);
+
+    for (i = 0; i < nready; i++) {
+        io_events = ucs_event_set_map_to_events(&events[i]);
+        event_set_handler(events[i].udata, io_events, arg);
+    }
+
+    *num_events = nready;
+    return UCS_OK;
+#else
     struct epoll_event *events;
     int nready, i, io_events;
 
@@ -217,6 +353,7 @@ ucs_status_t ucs_event_set_wait(ucs_sys_event_set_t *e
 
     *num_events = nready;
     return UCS_OK;
+#endif
 }
 
 void ucs_event_set_cleanup(ucs_sys_event_set_t *event_set)
