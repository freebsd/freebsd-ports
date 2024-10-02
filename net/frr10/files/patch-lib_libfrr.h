--- lib/libfrr.h.orig	2024-09-12 07:46:05 UTC
+++ lib/libfrr.h
@@ -188,7 +188,7 @@ extern bool frr_is_startup_fd(int fd);
 extern enum frr_cli_mode frr_get_cli_mode(void);
 extern uint32_t frr_get_fd_limit(void);
 extern bool frr_is_startup_fd(int fd);
-
+extern bool frr_is_daemon(void);
 /* call order of these hooks is as ordered here */
 DECLARE_HOOK(frr_early_init, (struct event_loop * tm), (tm));
 DECLARE_HOOK(frr_late_init, (struct event_loop * tm), (tm));
