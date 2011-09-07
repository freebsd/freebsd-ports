--- mbdyn/base/solver.cc.orig	2011-06-20 14:55:12.000000000 -0400
+++ mbdyn/base/solver.cc	2011-08-26 05:08:45.000000000 -0400
@@ -111,10 +111,17 @@
 };
 
 volatile sig_atomic_t mbdyn_keep_going = MBDYN_KEEP_GOING;
+#if defined(__FreeBSD__)
+__sighandler_t *mbdyn_sh_term = SIG_DFL;
+__sighandler_t *mbdyn_sh_int = SIG_DFL;
+__sighandler_t *mbdyn_sh_hup = SIG_DFL;
+__sighandler_t *mbdyn_sh_pipe = SIG_DFL;
+#else
 __sighandler_t mbdyn_sh_term = SIG_DFL;
 __sighandler_t mbdyn_sh_int = SIG_DFL;
 __sighandler_t mbdyn_sh_hup = SIG_DFL;
 __sighandler_t mbdyn_sh_pipe = SIG_DFL;
+#endif
 
 extern "C" void
 mbdyn_really_exit_handler(int signum)
@@ -202,7 +209,11 @@
 mbdyn_signal_init(int pre)
 {
 #ifdef HAVE_SIGNAL
+#if defined(__FreeBSD__)
+	__sighandler_t *hdl;
+#else
 	__sighandler_t hdl;
+#endif
 	if (pre) {
 		hdl = mbdyn_really_exit_handler;
 
@@ -464,8 +475,8 @@
 		}
 	}
 
-#ifdef USE_SCHUR
 	int mpi_finalize = 0;
+#ifdef USE_SCHUR
 
 	int MyRank = 0;
 	if (bParallel) {
