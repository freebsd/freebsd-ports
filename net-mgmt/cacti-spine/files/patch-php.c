--- php.c.orig	Tue Jul 19 10:58:48 2005
+++ php.c	Tue Jul 19 10:59:01 2005
@@ -149,27 +149,9 @@
 	int  cancel_state;
 	char *result_string;
 
-	/* variable to set/get environment limitations */
-	struct rlimit ResourceLimits;
-    struct rusage Usage;
-
 	/* initialize the php process id */
 	set.php_sspid = 0;
 	
-    if (getrlimit(RLIMIT_STACK,&ResourceLimits) == 0) {
-		if (set.verbose == POLLER_VERBOSITY_DEBUG) {
-			printf("DEBUG: Current Max Memory Allocation is '%i' bytes\n", ResourceLimits.rlim_cur);
-	        printf("DEBUG: Maximum Max Memory Allocation is '%i' bytes\n", ResourceLimits.rlim_max);
-		}
-    }
-
-    if (getrlimit(RLIMIT_AS,&ResourceLimits) == 0) {
-		if (set.verbose == POLLER_VERBOSITY_DEBUG) {
-			printf("DEBUG: Current Address Space Allocation is '%i' bytes\n", ResourceLimits.rlim_cur);
-	        printf("DEBUG: Maximum Address Space Allocation is '%i' bytes\n", ResourceLimits.rlim_max);
-		}
-    }
-
 	if (set.verbose == POLLER_VERBOSITY_DEBUG) {
 		snprintf(logmessage, LOGSIZE-1, "DEBUG: PHP Script Server Routine Starting\n");
 		cacti_log(logmessage);
