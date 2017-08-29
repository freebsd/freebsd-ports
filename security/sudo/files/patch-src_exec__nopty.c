--- src/exec_nopty.c.orig	2017-08-28 20:07:24.296708000 -0700
+++ src/exec_nopty.c	2017-08-28 20:17:50.768102000 -0700
@@ -134,6 +134,14 @@ signal_cb_nopty(int signo, int what, void *v)
 	    sudo_ev_loopexit(ec->evbase);
 	}
 	debug_return;
+#if defined(SIGINFO) && defined(__FreeBSD__)
+    /*
+     * FreeBSD's ^T (terminal STATUS) will send a kernel-generated SIGINFO
+     * to the controlling terminal's process group that should not be
+     * forwarded.
+     */
+    case SIGINFO:
+#endif
     case SIGINT:
     case SIGQUIT:
     case SIGTSTP:
