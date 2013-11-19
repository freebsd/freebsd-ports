--- deps/uv/src/unix/kqueue.orig    2013-11-18 23:14:54.000000000 -0200
+++ deps/uv/src/unix/kqueue.c 2013-11-18 23:16:51.000000000 -0200
@@ -263,6 +263,25 @@
   }
 }
 
+ 
+void uv__platform_invalidate_fd(uv_loop_t* loop, int fd) {
+  struct kevent* events;
+  uintptr_t i;
+  uintptr_t nfds;
+
+  assert(loop->watchers != NULL);
+
+ events = (struct kevent*) loop->watchers[loop->nwatchers];
+  nfds = (uintptr_t) loop->watchers[loop->nwatchers + 1];
+  if (events == NULL)
+    return;
+
+  /* Invalidate events with same file descriptor */
+  for (i = 0; i < nfds; i++)
+    if ((int) events[i].ident == fd)
+      events[i].ident = -1;
+}
+
 
 static void uv__fs_event(uv_loop_t* loop, uv__io_t* w, unsigned int fflags) {
   uv_fs_event_t* handle;
