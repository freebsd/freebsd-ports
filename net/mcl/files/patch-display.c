--- flute/display.c.orig	Wed Jan  7 12:08:23 2004
+++ flute/display.c	Wed Jan  7 12:07:24 2004
@@ -65,7 +65,11 @@
 	signal (SIGTERM, sig_catcher);
 	sigaction (SIGTERM, (struct sigaction *) 0, &sa);
 	sa.sa_flags |= SA_RESTART;
+#if defined(FREEBSD)
+	sa.sa_flags &= ~SA_NOCLDSTOP;
+#else
 	sa.sa_flags &= ~SA_INTERRUPT;
+#endif
 	sigaction (SIGTERM, &sa, (struct sigaction *) 0);
 	sigaction (SIGINT, &sa, (struct sigaction *) 0);
 	tcsetattr(0, TCSANOW, &new_settings);
