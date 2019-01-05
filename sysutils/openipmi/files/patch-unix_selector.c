--- unix/selector.c.orig	2018-12-28 13:36:00 UTC
+++ unix/selector.c
@@ -459,7 +459,13 @@ i_sel_clear_fd_handler(struct selector_s
 	fdc->state = NULL;
 
 	sel_update_epoll(sel, fd, EPOLL_CTL_DEL, 0);
+	/* We do not set HAVE_EPOLL_PWAIT, so 'fd_control_s' will never
+	 * have 'saved_events', and sel_update_epoll() will always return 1.
+	 * 
+	 * See lines 340 (HAVE_EPOLL_PWAIT), and 369 (no HAVE_EPOLL_PWAIT).
+	 *
 	fdc->saved_events = 0;
+	 */
     }
 
     init_fd(fdc);
