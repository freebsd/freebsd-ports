--- clients/clickdot.c.orig	2016-05-19 21:36:04 UTC
+++ clients/clickdot.c
@@ -29,11 +29,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <errno.h>
 #include <cairo.h>
 #include <math.h>
 #include <assert.h>
-#include <sys/timerfd.h>
-#include <sys/epoll.h>
 #include <unistd.h>
 
 #include <linux/input.h>
@@ -62,7 +61,7 @@ struct clickdot {
 	int reset;
 
 	struct input *cursor_timeout_input;
-	int cursor_timeout_fd;
+	struct event *cursor_timeout_ev;
 	struct task cursor_timeout_task;
 };
 
@@ -225,13 +224,12 @@ static void
 cursor_timeout_reset(struct clickdot *clickdot)
 {
 	const long cursor_timeout = 500;
-	struct itimerspec its;
+	struct timeval tv;
 
-	its.it_interval.tv_sec = 0;
-	its.it_interval.tv_nsec = 0;
-	its.it_value.tv_sec = cursor_timeout / 1000;
-	its.it_value.tv_nsec = (cursor_timeout % 1000) * 1000 * 1000;
-	timerfd_settime(clickdot->cursor_timeout_fd, 0, &its, NULL);
+	tv.tv_sec = cursor_timeout / 1000;
+	tv.tv_usec = (cursor_timeout % 1000) * 1000;
+
+	event_add(clickdot->cursor_timeout_ev, &tv);
 }
 
 static int
@@ -271,15 +269,11 @@ leave_handler(struct widget *widget,
 }
 
 static void
-cursor_timeout_func(struct task *task, uint32_t events)
+cursor_timeout_func(evutil_socket_t fd, short what, void *arg)
 {
+	struct task * task = (struct task *)arg;
 	struct clickdot *clickdot =
 		container_of(task, struct clickdot, cursor_timeout_task);
-	uint64_t exp;
-
-	if (read(clickdot->cursor_timeout_fd, &exp, sizeof (uint64_t)) !=
-	    sizeof(uint64_t))
-		abort();
 
 	input_set_pointer_image(clickdot->cursor_timeout_input,
 				CURSOR_LEFT_PTR);
@@ -317,12 +311,10 @@ clickdot_create(struct display *display)
 	clickdot->line.old_y = -1;
 	clickdot->reset = 0;
 
-	clickdot->cursor_timeout_fd =
-		timerfd_create(CLOCK_MONOTONIC, TFD_CLOEXEC);
 	clickdot->cursor_timeout_task.run = cursor_timeout_func;
-	display_watch_fd(window_get_display(clickdot->window),
-			 clickdot->cursor_timeout_fd,
-			 EPOLLIN, &clickdot->cursor_timeout_task);
+	clickdot->cursor_timeout_ev = display_add_oneshot_timer(
+	    window_get_display(clickdot->window),
+	    &clickdot->cursor_timeout_task);
 
 	return clickdot;
 }
@@ -330,9 +322,7 @@ clickdot_create(struct display *display)
 static void
 clickdot_destroy(struct clickdot *clickdot)
 {
-	display_unwatch_fd(window_get_display(clickdot->window),
-			   clickdot->cursor_timeout_fd);
-	close(clickdot->cursor_timeout_fd);
+	event_free(clickdot->cursor_timeout_ev);
 	if (clickdot->buffer)
 		cairo_surface_destroy(clickdot->buffer);
 	widget_destroy(clickdot->widget);
@@ -348,7 +338,8 @@ main(int argc, char *argv[])
 
 	display = display_create(&argc, argv);
 	if (display == NULL) {
-		fprintf(stderr, "failed to create display: %m\n");
+		fprintf(stderr, "failed to create display: %s\n",
+		    strerror(errno));
 		return -1;
 	}
 
