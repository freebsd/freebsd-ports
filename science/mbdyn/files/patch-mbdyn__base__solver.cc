--- mbdyn/base/solver.cc.orig	2009-06-24 16:13:44.000000000 +0200
+++ mbdyn/base/solver.cc	2010-10-31 23:38:30.000000000 +0100
@@ -109,10 +109,17 @@
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
@@ -456,8 +463,8 @@
 		}
 	}
 
-#ifdef USE_SCHUR
 	int mpi_finalize = 0;
+#ifdef USE_SCHUR
 
 	int MyRank = 0;
 	if (bParallel) {
