--- api/boinc_api.C.orig	Sat Mar 19 16:39:16 2005
+++ api/boinc_api.C	Mon Mar 21 11:08:09 2005
@@ -59,7 +59,7 @@
 static APP_INIT_DATA aid;
 static FILE_LOCK file_lock;
 APP_CLIENT_SHM* app_client_shm = 0;
-static volatile double time_until_checkpoint;
+static volatile int time_until_checkpoint;
     // time until enable checkpoint
 static volatile double time_until_fraction_done_update;
     // time until report fraction done to core client
@@ -79,7 +79,7 @@
 static volatile int nrunning_ticks = 0;
 #endif
 
-#define TIMER_PERIOD 1.0
+#define TIMER_PERIOD 1
     // period of API timer
     // This determines the resolution of fraction done and CPU time reporting
     // to the core client, and of checkpoint enabling.
@@ -164,7 +164,7 @@
     // the following may not be needed, but do it anyway
     //
     fraction_done = -1;
-    time_until_checkpoint = aid.checkpoint_period;
+    time_until_checkpoint = (int) aid.checkpoint_period;
     last_checkpoint_cpu_time = aid.wu_cpu_time;
     time_until_fraction_done_update = aid.fraction_done_update_period;
     last_wu_cpu_time = aid.wu_cpu_time;
@@ -548,8 +548,8 @@
         perror("boinc set_worker_timer() sigaction");
         return retval;
     }
-    value.it_value.tv_sec = (int)TIMER_PERIOD;
-    value.it_value.tv_usec = ((int)(TIMER_PERIOD*1000000))%1000000;
+    value.it_value.tv_sec = TIMER_PERIOD;
+    value.it_value.tv_usec = 0;
     value.it_interval = value.it_value;
     retval = setitimer(ITIMER_REAL, &value, NULL);
     if (retval) {
@@ -616,7 +616,7 @@
     last_checkpoint_cpu_time = last_wu_cpu_time;
     update_app_progress(last_checkpoint_cpu_time, last_checkpoint_cpu_time, 0);
     ready_to_checkpoint = false;
-    time_until_checkpoint = aid.checkpoint_period;
+    time_until_checkpoint = (int) aid.checkpoint_period;
 
     return 0;
 }
