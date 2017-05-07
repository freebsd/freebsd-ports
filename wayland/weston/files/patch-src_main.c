--- src/main.c.orig	2016-05-19 21:36:04 UTC
+++ src/main.c
@@ -84,7 +84,7 @@ sigchld_handler(int signal_number, void 
 	}
 
 	if (pid < 0 && errno != ECHILD)
-		weston_log("waitpid error %m\n");
+		weston_log("waitpid error %s\n", strerror(errno));
 
 	return 1;
 }
@@ -401,9 +401,14 @@ clock_name(clockid_t clk_id)
 	static const char *names[] = {
 		[CLOCK_REALTIME] =		"CLOCK_REALTIME",
 		[CLOCK_MONOTONIC] =		"CLOCK_MONOTONIC",
+#if defined(__FreeBSD__)
+		[CLOCK_REALTIME_FAST] =		"CLOCK_REALTIME_FAST",
+		[CLOCK_MONOTONIC_FAST] =	"CLOCK_MONOTONIC_FAST",
+#else
 		[CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW",
 		[CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE",
 		[CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE",
+#endif
 #ifdef CLOCK_BOOTTIME
 		[CLOCK_BOOTTIME] =		"CLOCK_BOOTTIME",
 #endif
@@ -437,7 +442,11 @@ weston_compositor_log_capabilities(struc
 				    yes ? "yes" : "no");
 	}
 
+#if defined(__FreeBSD__)
+	weston_log_continue(STAMP_SPACE "presentation clock: %s, id %ld\n",
+#else
 	weston_log_continue(STAMP_SPACE "presentation clock: %s, id %d\n",
+#endif
 			    clock_name(compositor->presentation_clock),
 			    compositor->presentation_clock);
 }
@@ -457,13 +466,15 @@ weston_create_listening_socket(struct wl
 {
 	if (socket_name) {
 		if (wl_display_add_socket(display, socket_name)) {
-			weston_log("fatal: failed to add socket: %m\n");
+			weston_log("fatal: failed to add socket: %s\n",
+			    strerror(errno));
 			return -1;
 		}
 	} else {
 		socket_name = wl_display_add_socket_auto(display);
 		if (!socket_name) {
-			weston_log("fatal: failed to add socket: %m\n");
+			weston_log("fatal: failed to add socket: %s\n",
+			    strerror(errno));
 			return -1;
 		}
 	}
@@ -1405,7 +1416,8 @@ int main(int argc, char *argv[])
 	if (fd != -1) {
 		primary_client = wl_client_create(display, fd);
 		if (!primary_client) {
-			weston_log("fatal: failed to add client: %m\n");
+			weston_log("fatal: failed to add client: %s\n",
+			    strerror(errno));
 			goto out;
 		}
 		primary_client_destroyed.notify =
