diff -urN core/Thread.h core/Thread.h
--- core/Thread.h	Wed May 26 05:51:32 2004
+++ core/Thread.h	Fri Nov 19 08:08:07 2004
@@ -10,7 +10,7 @@
 /* System headers */
 #if defined( HB_BEOS )
 #  include <OS.h>
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
 #  include <pthread.h>
 #elif defined( HB_CYGWIN )
 #  include <windows.h>
@@ -25,7 +25,7 @@
 #elif defined( HB_MACOSX )
 #  define HB_LOW_PRIORITY    0
 #  define HB_NORMAL_PRIORITY 31
-#elif defined( HB_LINUX ) || defined( HB_CYGWIN )
+#elif defined( HB_LINUX ) || defined( HB_CYGWIN ) || defined( HB_FREEBSD )
 /* Actually unused */
 #  define HB_LOW_PRIORITY    0
 #  define HB_NORMAL_PRIORITY 0
@@ -57,7 +57,7 @@
 {
 #if defined( HB_BEOS )
     sem_id          sem;
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_mutex_t mutex;
 #elif defined( HB_CYGWIN )
     HANDLE          mutex;
@@ -68,7 +68,7 @@
 {
 #if defined( HB_BEOS )
     acquire_sem( l->sem );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_mutex_lock( &l->mutex );
 #elif defined( HB_CYGWIN )
     WaitForSingleObject( l->mutex, INFINITE );
@@ -79,7 +79,7 @@
 {
 #if defined( HB_BEOS )
     release_sem( l->sem );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_mutex_unlock( &l->mutex );
 #elif defined( HB_CYGWIN )
     ReleaseMutex( l->mutex );
@@ -94,7 +94,7 @@
 {
 #if defined( HB_BEOS )
     int                 thread;
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_cond_t      cond;
 #elif defined( HB_CYGWIN )
     HANDLE              event;
@@ -110,7 +110,7 @@
     suspend_thread( c->thread );
     acquire_sem( lock->sem );
     c->thread = -1;
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_cond_wait( &c->cond, &lock->mutex );
 #elif defined( HB_CYGWIN )
     SignalObjectAndWait( lock->mutex, c->event, INFINITE, FALSE );
@@ -134,7 +134,7 @@
            release_sem() and suspend_thread() lines, wait a bit */
         snooze( 5000 );
     }
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_cond_signal( &c->cond );
 #elif defined( HB_CYGWIN )
     PulseEvent( c->event );
