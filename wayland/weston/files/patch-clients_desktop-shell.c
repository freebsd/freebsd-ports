--- clients/desktop-shell.c.orig	2016-05-19 21:36:04 UTC
+++ clients/desktop-shell.c
@@ -34,8 +34,6 @@
 #include <math.h>
 #include <cairo.h>
 #include <sys/wait.h>
-#include <sys/timerfd.h>
-#include <sys/epoll.h>
 #include <linux/input.h>
 #include <libgen.h>
 #include <ctype.h>
@@ -126,7 +124,7 @@ struct panel_clock {
 	struct widget *widget;
 	struct panel *panel;
 	struct task clock_task;
-	int clock_fd;
+	struct event *clockev;
 	char *format_string;
 	time_t refresh_timer;
 };
@@ -192,7 +190,7 @@ panel_launcher_activate(struct panel_lau
 
 	pid = fork();
 	if (pid < 0) {
-		fprintf(stderr, "fork failed: %m\n");
+		fprintf(stderr, "fork failed: %s\n", strerror(errno));
 		return;
 	}
 
@@ -201,7 +199,8 @@ panel_launcher_activate(struct panel_lau
 
 	argv = widget->argv.data;
 	if (execve(argv[0], argv, widget->envp.data) < 0) {
-		fprintf(stderr, "execl '%s' failed: %m\n", argv[0]);
+		fprintf(stderr, "execl '%s' failed: %s\n", argv[0],
+		    strerror(errno));
 		exit(1);
 	}
 }
@@ -338,14 +337,12 @@ panel_launcher_touch_up_handler(struct w
 }
 
 static void
-clock_func(struct task *task, uint32_t events)
+clock_func(evutil_socket_t fd, short what, void *arg)
 {
+	struct task *task = (struct task *)arg;
 	struct panel_clock *clock =
 		container_of(task, struct panel_clock, clock_task);
-	uint64_t exp;
 
-	if (read(clock->clock_fd, &exp, sizeof exp) != sizeof exp)
-		abort();
 	widget_schedule_redraw(clock->widget);
 }
 
@@ -390,16 +387,9 @@ panel_clock_redraw_handler(struct widget
 static int
 clock_timer_reset(struct panel_clock *clock)
 {
-	struct itimerspec its;
+	struct timeval tv = { .tv_sec = 60, .tv_usec = 0 };
 
-	its.it_interval.tv_sec = clock->refresh_timer;
-	its.it_interval.tv_nsec = 0;
-	its.it_value.tv_sec = clock->refresh_timer;
-	its.it_value.tv_nsec = 0;
-	if (timerfd_settime(clock->clock_fd, 0, &its, NULL) < 0) {
-		fprintf(stderr, "could not set timerfd\n: %m");
-		return -1;
-	}
+	event_add(clock->clockev, &tv);
 
 	return 0;
 }
@@ -409,7 +399,7 @@ panel_destroy_clock(struct panel_clock *
 {
 	widget_destroy(clock->widget);
 
-	close(clock->clock_fd);
+	event_free(clock->clockev);
 
 	free(clock);
 }
@@ -424,18 +414,10 @@ static void
 panel_add_clock(struct panel *panel)
 {
 	struct panel_clock *clock;
-	int timerfd;
-
-	timerfd = timerfd_create(CLOCK_MONOTONIC, TFD_CLOEXEC);
-	if (timerfd < 0) {
-		fprintf(stderr, "could not create timerfd\n: %m");
-		return;
-	}
 
 	clock = xzalloc(sizeof *clock);
 	clock->panel = panel;
 	panel->clock = clock;
-	clock->clock_fd = timerfd;
 
 	switch (panel->clock_format) {
 	case CLOCK_FORMAT_MINUTES:
@@ -449,8 +431,8 @@ panel_add_clock(struct panel *panel)
 	}
 
 	clock->clock_task.run = clock_func;
-	display_watch_fd(window_get_display(panel->window), clock->clock_fd,
-			 EPOLLIN, &clock->clock_task);
+	clock->clockev = display_add_periodic_timer
+	    (window_get_display(panel->window), &clock->clock_task);
 	clock_timer_reset(clock);
 
 	clock->widget = widget_add_widget(panel->widget, clock);
@@ -945,8 +927,9 @@ unlock_dialog_destroy(struct unlock_dial
 }
 
 static void
-unlock_dialog_finish(struct task *task, uint32_t events)
+unlock_dialog_finish(evutil_socket_t fd, short what, void *arg)
 {
+	struct task *task = (struct task *)arg;
 	struct desktop *desktop =
 		container_of(task, struct desktop, unlock_task);
 
@@ -1074,7 +1057,7 @@ background_create(struct desktop *deskto
 	weston_config_section_get_string(s, "background-type",
 					 &type, "tile");
 	if (type == NULL) {
-		fprintf(stderr, "%s: out of memory\n", program_invocation_short_name);
+		fprintf(stderr, "%s: out of memory\n", getprogname());
 		exit(EXIT_FAILURE);
 	}
 
@@ -1356,7 +1339,8 @@ int main(int argc, char *argv[])
 
 	desktop.display = display_create(&argc, argv);
 	if (desktop.display == NULL) {
-		fprintf(stderr, "failed to create display: %m\n");
+		fprintf(stderr, "failed to create display: %s\n",
+		    strerror(errno));
 		return -1;
 	}
 
@@ -1372,7 +1356,7 @@ int main(int argc, char *argv[])
 
 	grab_surface_create(&desktop);
 
-	signal(SIGCHLD, sigchild_handler);
+	/* signal(SIGCHLD, sigchild_handler); */
 
 	display_run(desktop.display);
 
