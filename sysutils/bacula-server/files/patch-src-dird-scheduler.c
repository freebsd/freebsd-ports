--- src/dird/scheduler.c	4 Jun 2006 12:24:39 -0000	1.33.2.2
+++ src/dird/scheduler.c	24 Jun 2006 17:25:58 -0000
@@ -151,6 +151,7 @@
               free(next_job);
           }
           schedules_invalidated = false;
+          unlock_jobs();
           goto again;
       }
       unlock_jobs();
