--- api/boinc_api.C.orig	Sat Mar 19 16:39:16 2005
+++ api/boinc_api.C	Wed Mar 23 15:49:01 2005
@@ -56,6 +56,8 @@
 // Unless otherwise noted, "CPU time" refers to the sum over all episodes
 // (not counting the part after the last checkpoint in an episode).
 
+pthread_t timer_thread_handle;
+
 static APP_INIT_DATA aid;
 static FILE_LOCK file_lock;
 APP_CLIENT_SHM* app_client_shm = 0;
@@ -506,6 +508,19 @@
 #endif
 }
 
+#ifndef _USECONDS_T_DECLARED
+typedef unsigned int useconds_t;
+#endif
+
+void *
+timer_thread(void *)
+{
+	while(1) {
+		usleep((useconds_t)(TIMER_PERIOD*1000000));
+		worker_timer(0);
+	}
+	/*NOTREACHED*/
+}
 
 // set up a periodic timer interrupt for the worker thread.
 // This is called only and always by the worker thread
@@ -539,21 +554,9 @@
     //
     SetThreadPriority(worker_thread_handle, THREAD_PRIORITY_LOWEST);
 #else
-    struct sigaction sa;
-    itimerval value;
-    sa.sa_handler = worker_timer;
-    sa.sa_flags = SA_RESTART;
-    retval = sigaction(SIGALRM, &sa, NULL);
-    if (retval) {
-        perror("boinc set_worker_timer() sigaction");
-        return retval;
-    }
-    value.it_value.tv_sec = (int)TIMER_PERIOD;
-    value.it_value.tv_usec = ((int)(TIMER_PERIOD*1000000))%1000000;
-    value.it_interval = value.it_value;
-    retval = setitimer(ITIMER_REAL, &value, NULL);
+    retval = pthread_create(&timer_thread_handle, NULL, timer_thread, NULL);
     if (retval) {
-        perror("boinc set_worker_timer() setitimer");
+        perror("boinc set_worker_timer() pthread_create(timer_thread)");
     }
 #endif
     return retval;
