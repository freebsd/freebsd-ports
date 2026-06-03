--- src/ucs/async/signal.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/async/signal.c
@@ -220,15 +220,30 @@ static void ucs_async_signal_handler(int signo, siginf
     case POLL_ERR:
     case POLL_MSG:
     case POLL_PRI:
+    {
+#if defined(__linux__)
         ucs_trace_async("async signal handler called for fd %d", siginfo->si_fd);
         ucs_async_dispatch_handlers(&siginfo->si_fd, 1,
                                     ucs_signal_map_to_events(siginfo->si_code));
+#else
+    /*
+     * FreeBSD does not provide si_fd in siginfo_t for SIGIO-style delivery,
+     * so we can't know which fd triggered the signal here.
+     *
+     * Fallback: dispatch without a specific fd. UCX usually treats fd<0 as
+     * "dispatch all"
+     */
+    int fd = -1;
+    ucs_trace_async("async signal handler called (no si_fd on this platform)");
+    ucs_async_dispatch_handlers(&fd, 1, ucs_signal_map_to_events(siginfo->si_code));
+#endif
         return;
     default:
         ucs_warn("signal handler called with unexpected event code %d, ignoring",
                  siginfo->si_code);
         return;
     }
+    }
 }
 
 static void ucs_async_signal_allow(int allow)
@@ -382,11 +397,13 @@ static ucs_status_t ucs_async_signal_add_event_fd(ucs_
     /* Send signal when fd is ready */
     ucs_trace_async("fcntl(F_STSIG, fd=%d, sig=%s)", event_fd,
                     ucs_signal_names[ucs_global_opts.async_signo]);
+#if defined(__linux__)
     if (0 > fcntl(event_fd, F_SETSIG, ucs_global_opts.async_signo)) {
         ucs_error("fcntl F_SETSIG failed: %m");
         status = UCS_ERR_IO_ERROR;
         goto err_remove_handler;
     }
+#endif
 
     /* Send the signal to the desired thread */
     tid = ucs_async_signal_context_tid(async);
