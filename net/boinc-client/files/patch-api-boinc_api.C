--- api/boinc_api.C.orig	Mon May 23 03:50:50 2005
+++ api/boinc_api.C	Wed Jun  8 16:52:34 2005
@@ -59,7 +59,7 @@
 
 #ifndef _WIN32
 static pthread_t timer_thread_handle;
-static pthread_t worker_thread;
+static void * timer_thread();
 static struct rusage worker_thread_ru;
 #endif
 
@@ -534,14 +534,6 @@
     }
 }
 
-#ifndef _WIN32
-static void timer_signal_handler(int) {
-    if (pthread_equal(pthread_self(), worker_thread)) {
-        getrusage(RUSAGE_SELF, &worker_thread_ru);
-    }
-}
-
-#endif
 
 #ifdef _WIN32
 static void CALLBACK worker_timer(
@@ -619,6 +611,7 @@
     while(1) {
         usleep((useconds_t)(TIMER_PERIOD*1000000));
         worker_timer(0);
+        getrusage(RUSAGE_SELF, &worker_thread_ru);
     }
     /*NOTREACHED*/
 }
@@ -659,24 +652,6 @@
     retval = pthread_create(&timer_thread_handle, NULL, timer_thread, NULL);
     if (retval) {
         perror("set_worker_timer(): pthread_create(): %d");
-    }
-    worker_thread = pthread_self();
-
-    struct sigaction sa;
-    itimerval value;
-    sa.sa_handler = timer_signal_handler;
-    sa.sa_flags = SA_RESTART;
-    retval = sigaction(SIGALRM, &sa, NULL);
-    if (retval) {
-        perror("boinc set_worker_timer() sigaction");
-        return retval;
-    }
-    value.it_value.tv_sec = TIMER_PERIOD;
-    value.it_value.tv_usec = 0;
-    value.it_interval = value.it_value;
-    retval = setitimer(ITIMER_REAL, &value, NULL);
-    if (retval) {
-        perror("boinc set_worker_timer() setitimer");
     }
 #endif
     return retval;
