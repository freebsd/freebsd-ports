--- src/event-loop.c.orig	2016-02-17 01:13:16 UTC
+++ src/event-loop.c
@@ -23,6 +23,8 @@
  * SOFTWARE.
  */
 
+#include "../config.h"
+
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
@@ -32,16 +34,30 @@
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#ifdef HAVE_SYS_SIGNALFD_H
 #include <sys/signalfd.h>
+#endif /* signalfd */
+#ifdef HAVE_SYS_TIMERFD_H
 #include <sys/timerfd.h>
+#endif /* timerfd */
+#elif HAVE_SYS_EVENT_H
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#else /* !epoll && !kqueue */
+#error "Unsupported event system. Only epoll and kqueue are supported."
+#endif
+
 #include <unistd.h>
 #include "wayland-private.h"
 #include "wayland-server.h"
 #include "wayland-os.h"
 
 struct wl_event_loop {
-	int epoll_fd;
+	int event_fd;
 	struct wl_list check_list;
 	struct wl_list idle_list;
 	struct wl_list destroy_list;
@@ -50,8 +66,13 @@ struct wl_event_loop {
 };
 
 struct wl_event_source_interface {
+#ifdef HAVE_SYS_EPOLL_H
 	int (*dispatch)(struct wl_event_source *source,
 			struct epoll_event *ep);
+#elif HAVE_SYS_EVENT_H
+	int (*dispatch)(struct wl_event_source *source,
+			struct kevent *ep);
+#endif
 };
 
 struct wl_event_source {
@@ -68,6 +89,7 @@ struct wl_event_source_fd {
 	int fd;
 };
 
+#ifdef HAVE_SYS_EPOLL_H
 static int
 wl_event_source_fd_dispatch(struct wl_event_source *source,
 			    struct epoll_event *ep)
@@ -87,11 +109,33 @@ wl_event_source_fd_dispatch(struct wl_ev
 
 	return fd_source->func(fd_source->fd, mask, source->data);
 }
+#elif HAVE_SYS_EVENT_H
+static int
+wl_event_source_fd_dispatch(struct wl_event_source *source,
+                           struct kevent *ev)
+{
+       struct wl_event_source_fd *fd_source =
+               (struct wl_event_source_fd *) source;
+       uint32_t mask;
+
+       mask = 0;
+       if (ev->filter == EVFILT_READ)
+               mask |= WL_EVENT_READABLE;
+       if (ev->filter == EVFILT_WRITE)
+               mask |= WL_EVENT_WRITABLE;
+       if (ev->flags & EV_ERROR)
+               mask |= WL_EVENT_ERROR;
+
+       return fd_source->func(fd_source->fd, mask, source->data);
+}
+#endif
+
 
 struct wl_event_source_interface fd_source_interface = {
 	wl_event_source_fd_dispatch,
 };
 
+#ifdef HAVE_SYS_EPOLL_H
 static struct wl_event_source *
 add_source(struct wl_event_loop *loop,
 	   struct wl_event_source *source, uint32_t mask, void *data)
@@ -114,7 +158,7 @@ add_source(struct wl_event_loop *loop,
 		ep.events |= EPOLLOUT;
 	ep.data.ptr = source;
 
-	if (epoll_ctl(loop->epoll_fd, EPOLL_CTL_ADD, source->fd, &ep) < 0) {
+	if (epoll_ctl(loop->event_fd, EPOLL_CTL_ADD, source->fd, &ep) < 0) {
 		close(source->fd);
 		free(source);
 		return NULL;
@@ -122,6 +166,47 @@ add_source(struct wl_event_loop *loop,
 
 	return source;
 }
+#elif HAVE_SYS_EVENT_H
+static struct wl_event_source *
+add_source(struct wl_event_loop *loop,
+	   struct wl_event_source *source, uint32_t mask, void *data)
+{
+	struct kevent events[2];
+       unsigned int num_events = 0;
+
+       if (source->fd < 0) {
+               fprintf(stderr, "could not add source\n: %m");
+               free(source);
+               return NULL;
+       }
+
+       source->loop = loop;
+       source->data = data;
+       wl_list_init(&source->link);
+
+       if (mask & WL_EVENT_READABLE) {
+               EV_SET(&events[num_events], source->fd, EVFILT_READ,
+                      EV_ADD | EV_ENABLE, 0, 0, source);
+               num_events++;
+       }
+
+       if (mask & WL_EVENT_WRITABLE) {
+               EV_SET(&events[num_events], source->fd, EVFILT_WRITE,
+                      EV_ADD | EV_ENABLE, 0, 0, source);
+               num_events++;
+       }
+
+       if (kevent(loop->event_fd, events, num_events, NULL, 0, NULL) < 0) {
+               fprintf(stderr, "error adding source %i (%p) to loop %p: %s\n",
+                       source->fd, source, loop, strerror(errno));
+               close(source->fd);
+               free(source);
+               return NULL;
+       }
+
+       return source;
+}
+#endif
 
 WL_EXPORT struct wl_event_source *
 wl_event_loop_add_fd(struct wl_event_loop *loop,
@@ -143,6 +228,7 @@ wl_event_loop_add_fd(struct wl_event_loo
 	return add_source(loop, &source->base, mask, data);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 WL_EXPORT int
 wl_event_source_fd_update(struct wl_event_source *source, uint32_t mask)
 {
@@ -156,27 +242,62 @@ wl_event_source_fd_update(struct wl_even
 		ep.events |= EPOLLOUT;
 	ep.data.ptr = source;
 
-	return epoll_ctl(loop->epoll_fd, EPOLL_CTL_MOD, source->fd, &ep);
+	return epoll_ctl(loop->event_fd, EPOLL_CTL_MOD, source->fd, &ep);
+}
+#elif HAVE_SYS_EVENT_H
+WL_EXPORT int
+wl_event_source_fd_update(struct wl_event_source *source, uint32_t mask)
+{
+       struct wl_event_loop *loop = source->loop;
+       struct kevent events[2];
+       unsigned int num_events = 0;
+
+       if (mask & WL_EVENT_READABLE) {
+       EV_SET(&events[num_events], source->fd, EVFILT_READ,
+                      EV_ADD | EV_ENABLE, 0, 0, source);
+               num_events++;
+       }
+
+       if (mask & WL_EVENT_WRITABLE) {
+               EV_SET(&events[num_events], source->fd, EVFILT_WRITE,
+                      EV_ADD | EV_ENABLE, 0, 0, source);
+               num_events++;
+       }
+
+       return kevent(loop->event_fd, events, num_events, NULL, 0, NULL);
 }
+#endif
 
 struct wl_event_source_timer {
 	struct wl_event_source base;
 	wl_event_loop_timer_func_t func;
 };
 
+#ifdef HAVE_SYS_EPOLL_H
 static int
 wl_event_source_timer_dispatch(struct wl_event_source *source,
 			       struct epoll_event *ep)
+#elif HAVE_SYS_EVENT_H
+static int
+wl_event_source_timer_dispatch(struct wl_event_source *source,
+                              struct kevent *ev)
+#endif
 {
 	struct wl_event_source_timer *timer_source =
 		(struct wl_event_source_timer *) source;
 	uint64_t expires;
+#ifdef HAVE_SYS_TIMERFD_H
 	int len;
 
+	/* Linux. Read the number of missed expirations from the FD. */
 	len = read(source->fd, &expires, sizeof expires);
 	if (!(len == -1 && errno == EAGAIN) && len != sizeof expires)
 		/* Is there anything we can do here?  Will this ever happen? */
 		wl_log("timerfd read error: %m\n");
+#else
+	/* FreeBSD. Grab the number of missed expires from the kevent. */
+	expires = ev->data;
+#endif
 
 	return timer_source->func(timer_source->base.data);
 }
@@ -197,16 +318,29 @@ wl_event_loop_add_timer(struct wl_event_
 		return NULL;
 
 	source->base.interface = &timer_source_interface;
+	source->func = func;
+#ifdef HAVE_SYS_TIMERFD_H
 	source->base.fd = timerfd_create(CLOCK_MONOTONIC,
 					 TFD_CLOEXEC | TFD_NONBLOCK);
-	source->func = func;
 
 	return add_source(loop, &source->base, WL_EVENT_READABLE, data);
+#else
+       /* FreeBSD. We use kqueue() timers directly.
+        * See: wl_event_source_timer_update(). */
+       source->base.fd = 0;
+       source->base.loop = loop;
+       source->base.data = data;
+       wl_list_init(&source->base.link);
+
+       return &source->base;
+#endif
 }
 
 WL_EXPORT int
 wl_event_source_timer_update(struct wl_event_source *source, int ms_delay)
 {
+#ifdef HAVE_SYS_TIMERFD_H
+	/* Linux */
 	struct itimerspec its;
 
 	its.it_interval.tv_sec = 0;
@@ -217,6 +351,20 @@ wl_event_source_timer_update(struct wl_e
 		return -1;
 
 	return 0;
+#else
+        /* FreeBSD. */
+       struct kevent ev;
+
+       EV_SET(&ev, 0, EVFILT_TIMER, EV_ADD | EV_ENABLE | EV_ONESHOT, 0,
+              ms_delay, source);
+
+       if (kevent(source->loop->event_fd, &ev, 1, NULL, 0, NULL) < 0) {
+               fprintf(stderr, "could not set kqueue timer\n: %m");
+               return -1;
+       }
+
+       return 0;
+#endif
 }
 
 struct wl_event_source_signal {
@@ -225,12 +373,19 @@ struct wl_event_source_signal {
 	wl_event_loop_signal_func_t func;
 };
 
+#ifdef HAVE_SYS_EPOLL_H
 static int
 wl_event_source_signal_dispatch(struct wl_event_source *source,
 			       struct epoll_event *ep)
+#elif HAVE_SYS_EVENT_H
+static int
+wl_event_source_signal_dispatch(struct wl_event_source *source,
+                               struct kevent *ev)
+#endif
 {
 	struct wl_event_source_signal *signal_source =
 		(struct wl_event_source_signal *) source;
+#ifdef HAVE_SYS_SIGNALFD_H
 	struct signalfd_siginfo signal_info;
 	int len;
 
@@ -238,6 +393,7 @@ wl_event_source_signal_dispatch(struct w
 	if (!(len == -1 && errno == EAGAIN) && len != sizeof signal_info)
 		/* Is there anything we can do here?  Will this ever happen? */
 		wl_log("signalfd read error: %m\n");
+#endif
 
 	return signal_source->func(signal_source->signal_number,
 				   signal_source->base.data);
@@ -255,6 +411,9 @@ wl_event_loop_add_signal(struct wl_event
 {
 	struct wl_event_source_signal *source;
 	sigset_t mask;
+#ifndef HAVE_SYS_SIGNALFD_H
+       struct kevent ev;
+#endif
 
 	source = malloc(sizeof *source);
 	if (source == NULL)
@@ -262,15 +421,37 @@ wl_event_loop_add_signal(struct wl_event
 
 	source->base.interface = &signal_source_interface;
 	source->signal_number = signal_number;
+	source->func = func;
 
+	/* Block delivery of signal_number to this process. */
 	sigemptyset(&mask);
 	sigaddset(&mask, signal_number);
-	source->base.fd = signalfd(-1, &mask, SFD_CLOEXEC | SFD_NONBLOCK);
 	sigprocmask(SIG_BLOCK, &mask, NULL);
 
-	source->func = func;
+#ifdef HAVE_SYS_SIGNALFD_H
+	/* Linux. Use signalfd. */
+	source->base.fd = signalfd(-1, &mask, SFD_CLOEXEC | SFD_NONBLOCK);
 
 	return add_source(loop, &source->base, WL_EVENT_READABLE, data);
+#else
+	/* FreeBSD. Use kqueue() signals directly. */
+       source->base.fd = 0;
+       source->base.loop = loop;
+       source->base.data = data;
+       wl_list_init(&source->base.link);
+
+       EV_SET(&ev, signal_number, EVFILT_SIGNAL, EV_ADD | EV_ENABLE, 0, 0,
+              source);
+
+       if (kevent(loop->event_fd, &ev, 1, NULL, 0, NULL) < 0) {
+               fprintf(stderr, "error adding signal for %i (%p), %p: %s\n",
+                       signal_number, source, loop, strerror(errno));
+		free(source);
+		return NULL;
+	}
+
+	return &source->base;
+#endif
 }
 
 struct wl_event_source_idle {
@@ -311,6 +492,8 @@ wl_event_source_check(struct wl_event_so
 	wl_list_insert(source->loop->check_list.prev, &source->link);
 }
 
+
+#ifdef HAVE_SYS_EPOLL_H
 WL_EXPORT int
 wl_event_source_remove(struct wl_event_source *source)
 {
@@ -319,7 +502,7 @@ wl_event_source_remove(struct wl_event_s
 	/* We need to explicitly remove the fd, since closing the fd
 	 * isn't enough in case we've dup'ed the fd. */
 	if (source->fd >= 0) {
-		epoll_ctl(loop->epoll_fd, EPOLL_CTL_DEL, source->fd, NULL);
+		epoll_ctl(loop->event_fd, EPOLL_CTL_DEL, source->fd, NULL);
 		close(source->fd);
 		source->fd = -1;
 	}
@@ -329,6 +512,82 @@ wl_event_source_remove(struct wl_event_s
 
 	return 0;
 }
+#elif HAVE_SYS_EVENT_H
+WL_EXPORT int
+wl_event_source_remove(struct wl_event_source *source)
+{
+       struct wl_event_loop *loop = source->loop;
+       int ret = 0, saved_errno = 0;
+
+       /* Since FreeBSD doesn't treat all event sources as FDs, we need to
+        * differentiate by source interface. */
+       if (source->interface == &fd_source_interface && source->fd >= 0) {
+               struct kevent ev[2];
+               int _ret[2], _saved_errno[2];
+
+               /* We haven't stored state about the mask used when adding the
+                * source, so we have to try and remove both READ and WRITE
+                * filters. One may fail, which is OK. Removal of the source has
+                * only failed if _both_ kevent() calls fail. We have to do two
+                * kevent() calls so that we can get independent return values
+                * for the two kevents. */
+               EV_SET(&ev[0], source->fd, EVFILT_READ, EV_DELETE, 0, 0,
+                      source);
+               EV_SET(&ev[1], source->fd, EVFILT_WRITE, EV_DELETE, 0, 0,
+                      source);
+
+               _ret[0] = kevent(loop->event_fd, &ev[0], 1, NULL, 0, NULL);
+               _saved_errno[0] = errno;
+               _ret[1] = kevent(loop->event_fd, &ev[1], 1, NULL, 0, NULL);
+               _saved_errno[1] = errno;
+
+               if (_ret[0] >= _ret[1]) {
+                       ret = _ret[0];
+                       saved_errno = _saved_errno[0];
+               } else {
+                       ret = _ret[1];
+                       saved_errno = _saved_errno[1];
+               }
+
+               close(source->fd);
+       } else if (source->interface == &timer_source_interface) {
+               struct kevent ev;
+
+               /* Only one kevent() call needed. */
+               EV_SET(&ev, 0, EVFILT_TIMER, EV_DELETE, 0, 0, source);
+               ret = kevent(loop->event_fd, &ev, 1, NULL, 0, NULL);
+               saved_errno = errno;
+       } else if (source->interface == &signal_source_interface) {
+               struct kevent ev;
+               int signal_number;
+               struct wl_event_source_signal *_source;
+
+               /* Only one kevent() call needed. */
+               _source = (struct wl_event_source_signal *) source;
+               signal_number = _source->signal_number;
+
+               EV_SET(&ev, signal_number, EVFILT_SIGNAL, EV_DELETE, 0, 0,
+                      source);
+               ret = kevent(loop->event_fd, &ev, 1, NULL, 0, NULL);
+               saved_errno = errno;
+       }
+
+       /* Handle any errors from kevent() calls. */
+       if (ret < 0) {
+               fprintf (stderr,
+                        "error removing event (%i) from kqueue: %s\n",
+                        source->fd, strerror(saved_errno));
+       }
+
+       /* Tidy up the source. */
+       source->fd = -1;
+
+       wl_list_remove(&source->link);
+       wl_list_insert(&loop->destroy_list, &source->link);
+
+       return 0;
+}
+#endif
 
 static void
 wl_event_loop_process_destroy_list(struct wl_event_loop *loop)
@@ -350,11 +609,20 @@ wl_event_loop_create(void)
 	if (loop == NULL)
 		return NULL;
 
-	loop->epoll_fd = wl_os_epoll_create_cloexec();
-	if (loop->epoll_fd < 0) {
+#ifdef HAVE_SYS_EPOLL_H
+	loop->event_fd = wl_os_epoll_create_cloexec();
+	if (loop->event_fd < 0) {
+		free(loop);
+		return NULL;
+	}
+#elif HAVE_SYS_EVENT_H
+	loop->event_fd = wl_os_kqueue_create_cloexec();
+	if (loop->event_fd < 0) {
 		free(loop);
 		return NULL;
 	}
+#endif
+
 	wl_list_init(&loop->check_list);
 	wl_list_init(&loop->idle_list);
 	wl_list_init(&loop->destroy_list);
@@ -370,10 +638,11 @@ wl_event_loop_destroy(struct wl_event_lo
 	wl_signal_emit(&loop->destroy_signal, loop);
 
 	wl_event_loop_process_destroy_list(loop);
-	close(loop->epoll_fd);
+	close(loop->event_fd);
 	free(loop);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 static int
 post_dispatch_check(struct wl_event_loop *loop)
 {
@@ -388,6 +657,22 @@ post_dispatch_check(struct wl_event_loop
 
 	return n;
 }
+#elif HAVE_SYS_EVENT_H
+static int
+post_dispatch_check(struct wl_event_loop *loop)
+{
+       struct kevent ev;
+       struct wl_event_source *source, *next;
+       int n;
+
+       ev.filter = 0;
+       n = 0;
+       wl_list_for_each_safe(source, next, &loop->check_list, link)
+               n += source->interface->dispatch(source, &ev);
+
+       return n;
+}
+#endif
 
 WL_EXPORT void
 wl_event_loop_dispatch_idle(struct wl_event_loop *loop)
@@ -402,6 +687,7 @@ wl_event_loop_dispatch_idle(struct wl_ev
 	}
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 WL_EXPORT int
 wl_event_loop_dispatch(struct wl_event_loop *loop, int timeout)
 {
@@ -411,7 +697,7 @@ wl_event_loop_dispatch(struct wl_event_l
 
 	wl_event_loop_dispatch_idle(loop);
 
-	count = epoll_wait(loop->epoll_fd, ep, ARRAY_LENGTH(ep), timeout);
+	count = epoll_wait(loop->event_fd, ep, ARRAY_LENGTH(ep), timeout);
 	if (count < 0)
 		return -1;
 
@@ -431,11 +717,48 @@ wl_event_loop_dispatch(struct wl_event_l
 
 	return 0;
 }
+#elif HAVE_SYS_EVENT_H
+WL_EXPORT int
+wl_event_loop_dispatch(struct wl_event_loop *loop, int timeout)
+{
+       struct kevent ev[32];
+       struct wl_event_source *source;
+       int i, count, n;
+       struct timespec timeout_spec;
+
+       wl_event_loop_dispatch_idle(loop);
+
+       /* timeout is provided in milliseconds; convert it to a timespec. */
+       timeout_spec.tv_sec = timeout / 1000;
+       timeout_spec.tv_nsec = (timeout % 1000) * 1000000;
+
+       count = kevent(loop->event_fd, NULL, 0, ev, ARRAY_LENGTH(ev),
+                      (timeout != -1) ? &timeout_spec : NULL);
+       if (count < 0)
+               return -1;
+
+       for (i = 0; i < count; i++) {
+               source = ev[i].udata;
+               if (source->fd != -1) {
+                       source->interface->dispatch(source, &ev[i]);
+               }
+       }
+
+       wl_event_loop_process_destroy_list(loop);
+
+       do {
+               n = post_dispatch_check(loop);
+       } while (n > 0);
+
+       return 0;
+}
+#endif
+
 
 WL_EXPORT int
 wl_event_loop_get_fd(struct wl_event_loop *loop)
 {
-	return loop->epoll_fd;
+	return loop->event_fd;
 }
 
 WL_EXPORT void
@@ -451,4 +774,3 @@ wl_event_loop_get_destroy_listener(struc
 {
 	return wl_signal_get(&loop->destroy_signal, notify);
 }
-
