--- src/cmd/INIT/mamake.c.orig	2026-02-25 16:06:24.000000000 -0800
+++ src/cmd/INIT/mamake.c	2026-03-01 08:17:37.760046000 -0800
@@ -3011,15 +3011,6 @@
 		state.maxjobs = 0;
 
 	/*
-	 * standards compliance for shell actions
-	 */
-
-	setenv("POSIXLY_CORRECT", "y", 1);
-#if __QNX__
-	setenv("POSIX_STRICT", "y", 1);  /* required for /bin/cp on QNX to update the target's last-modified date */
-#endif
-
-	/*
 	 * load the environment
 	 */
 
