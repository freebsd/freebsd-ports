
$FreeBSD$

--- gmond/gmond.c.orig	Tue Jan  7 09:05:04 2003
+++ gmond/gmond.c	Thu Apr  3 16:40:22 2003
@@ -163,6 +163,13 @@
    print_gmond_config();
    */
 
+   /* in machine.c */
+   initval = metric_init();
+   if ( initval.int32 <0)
+      {
+         err_quit("metric_init() returned an error");
+      }
+
    if(!gmond_config.no_setuid)
       become_a_nobody(gmond_config.setuid);
 
@@ -266,13 +273,6 @@
                return -1;
             }
          debug_msg("multicasting on channel %s %d", gmond_config.mcast_channel, gmond_config.mcast_port);
-
-         /* in machine.c */
-         initval = metric_init();
-         if ( initval.int32 <0)
-            {
-               err_quit("monitor_init() returned an error");
-            }
 
          pthread_create(&tid, &attr, monitor_thread, NULL);
          debug_msg("created monitor thread");
