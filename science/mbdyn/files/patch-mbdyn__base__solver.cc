--- mbdyn/base/solver.cc.orig	Thu Feb 10 14:49:22 2005
+++ mbdyn/base/solver.cc	Sat Feb 12 17:14:57 2005
@@ -95,10 +95,17 @@
 
 #ifdef HAVE_SIGNAL
 static volatile sig_atomic_t mbdyn_keep_going = 1;
+#if defined(__FreeBSD__)
+static __sighandler_t *mbdyn_sh_term = SIG_DFL;
+static __sighandler_t *mbdyn_sh_int = SIG_DFL;
+static __sighandler_t *mbdyn_sh_hup = SIG_DFL;
+static __sighandler_t *mbdyn_sh_pipe = SIG_DFL;
+#else
 static __sighandler_t mbdyn_sh_term = SIG_DFL;
 static __sighandler_t mbdyn_sh_int = SIG_DFL;
 static __sighandler_t mbdyn_sh_hup = SIG_DFL;
 static __sighandler_t mbdyn_sh_pipe = SIG_DFL;
+#endif
 
 static void
 really_exit_handler(int signum)
