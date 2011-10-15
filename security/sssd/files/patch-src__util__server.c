--- ./src/util/server.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/server.c	2011-10-13 12:15:03.000000000 -0400
@@ -296,14 +296,15 @@
 	BlockSignals(false, SIGTERM);
 
 	CatchSignal(SIGHUP, sig_hup);
-
 #ifndef HAVE_PRCTL
         /* If prctl is not defined on the system, try to handle
          * some common termination signals gracefully */
-	CatchSignal(SIGSEGV, sig_segv_abrt);
-	CatchSignal(SIGABRT, sig_segv_abrt);
+	/*
+	  CatchSignal(SIGSEGV, sig_segv_abrt);
+	  CatchSignal(SIGABRT, sig_segv_abrt);
+	*/
 #endif
-
+	
 }
 
 /*
