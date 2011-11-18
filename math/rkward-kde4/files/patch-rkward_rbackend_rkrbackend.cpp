--- rkward/rbackend/rkrbackend.cpp.orig	2011-10-18 10:29:11.000000000 +0200
+++ rkward/rbackend/rkrbackend.cpp	2011-11-12 22:08:00.000000000 +0100
@@ -1056,11 +1056,11 @@
 	if (backend_was_forked) return;
 	backend_was_forked = true;
 
-	// Block SIGCLD in the main thread from now on. I don't fully understand, why, but otherwise, these signals
+	// Block SIGCHLD in the main thread from now on. I don't fully understand, why, but otherwise, these signals
 	// interrupt the select() call in the fork()ing code of library(parallel)
 	sigset_t new_set;
 	sigemptyset (&new_set);
-	sigaddset (&new_set, SIGCLD);
+	sigaddset (&new_set, SIGCHLD);
 	pthread_sigmask (SIG_BLOCK, &new_set, NULL);
 
 //	This was used to show a warning message. Unfortunately, however, forks also occur on every popen (i.e. in system(..., intern=TRUE).
