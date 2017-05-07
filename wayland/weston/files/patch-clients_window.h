--- clients/window.h.orig	2016-05-19 21:36:04 UTC
+++ clients/window.h
@@ -27,6 +27,7 @@
 #include "config.h"
 
 #include <xkbcommon/xkbcommon.h>
+#include <event2/event.h>
 #include <wayland-client.h>
 #include <cairo.h>
 #include "shared/config-parser.h"
@@ -40,7 +41,7 @@ struct input;
 struct output;
 
 struct task {
-	void (*run)(struct task *task, uint32_t events);
+	void (*run)(evutil_socket_t fd, short what, void *arg);
 	struct wl_list link;
 };
 
@@ -151,9 +152,15 @@ display_get_pointer_image(struct display
 void
 display_defer(struct display *display, struct task *task);
 
-void
+struct event*
+display_add_periodic_timer(struct display *display, struct task *task);
+
+struct event*
+display_add_oneshot_timer(struct display *display, struct task *task);
+
+struct event *
 display_watch_fd(struct display *display,
-		 int fd, uint32_t events, struct task *task);
+		 int fd, short what, struct task *task);
 
 void
 display_unwatch_fd(struct display *display, int fd);
