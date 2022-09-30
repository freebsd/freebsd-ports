--- boreas/cli.c.orig	2022-09-30 08:26:50 UTC
+++ boreas/cli.c
@@ -162,8 +162,8 @@ run_cli_scan (scanner_t *scanner, alive_test_t alive_t
                                            scanner->hosts_data->alivehosts);
   gettimeofday (&end_time, NULL);
   if (scanner->print_results == 1)
-    printf ("Alive scan finished in %ld seconds: %d alive hosts of %d.\n",
-            end_time.tv_sec - start_time.tv_sec,
+    printf ("Alive scan finished in %lld seconds: %d alive hosts of %d.\n",
+            (long long)(end_time.tv_sec - start_time.tv_sec),
             number_of_targets - number_of_dead_hosts, number_of_targets);
 
   return error;
