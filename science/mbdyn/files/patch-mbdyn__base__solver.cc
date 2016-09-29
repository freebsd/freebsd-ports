--- mbdyn/base/solver.cc.orig	2016-04-24 19:10:43 UTC
+++ mbdyn/base/solver.cc
@@ -109,10 +109,17 @@ enum {
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
@@ -200,7 +207,11 @@ extern "C" void
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
 
@@ -406,8 +417,8 @@ Solver::Prepare(void)
 		pRTSolver->Setup();
 	}
 
-#ifdef USE_SCHUR
 	int mpi_finalize = 0;
+#ifdef USE_SCHUR
 
 	if (bParallel) {
 		DEBUGLCOUT(MYDEBUG_MEM, "creating parallel SchurDataManager"
