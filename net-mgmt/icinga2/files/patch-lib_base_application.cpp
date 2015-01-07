--- lib/base/application.cpp.orig	2015-01-07 20:24:52.914349279 +0100
+++ lib/base/application.cpp	2015-01-07 20:28:25.822333330 +0100
@@ -216,10 +216,7 @@
 		rl.rlim_max = RLIM_INFINITY;
 	}
 
-	if (set_stack_rlimit)
-		rl.rlim_cur = 256 * 1024;
-	else
-		rl.rlim_cur = rl.rlim_max;
+	rl.rlim_cur = rl.rlim_max;
 
 	if (setrlimit(RLIMIT_STACK, &rl) < 0)
 		Log(LogNotice, "Application", "Could not adjust resource limit for stack size (RLIMIT_STACK)");
