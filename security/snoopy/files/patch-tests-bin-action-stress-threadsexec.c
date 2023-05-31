--- tests/bin/action-stress-threadsexec.c.orig	2022-09-28 19:48:05 UTC
+++ tests/bin/action-stress-threadsexec.c
@@ -178,7 +178,7 @@ int snoopyTestCli_action_stress_threadsexec (int argc,
             } else {
                 int res;
 
-                res = pthread_tryjoin_np(snoopyTestCli_action_stress_threadsexec_tRepo[i], NULL);
+                res = pthread_peekjoin_np(snoopyTestCli_action_stress_threadsexec_tRepo[i], NULL);
                 if (res == EBUSY) {
                     if (verbose) printf("  M: Thread #%d has not finished executing yet.\n", i+1);
                     if (verbose) fflush(stdout);
