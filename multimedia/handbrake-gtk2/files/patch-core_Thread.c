diff -urN core/Thread.c core/Thread.c
--- core/Thread.c	Wed May 26 05:51:32 2004
+++ core/Thread.c	Fri Nov 19 08:08:07 2004
@@ -24,7 +24,7 @@
     /* OS-specific thread id */
 #if defined( HB_BEOS )
     int       thread;
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_t thread;
 #elif defined( HB_CYGWIN )
     HANDLE    thread;
@@ -74,7 +74,7 @@
     t->thread = spawn_thread( (int32 (*)( void * )) ThreadFunc,
                               name, priority, t );
     resume_thread( t->thread );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_create( &t->thread, NULL,
                     (void * (*)( void * )) ThreadFunc, t );
 #elif defined( HB_CYGWIN )
@@ -96,7 +96,7 @@
 #if defined( HB_BEOS )
     long exitValue;
     wait_for_thread( t->thread, &exitValue );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_join( t->thread, NULL );
 #elif defined( HB_CYGWIN )
     WaitForSingleObject( t->thread, INFINITE );
@@ -126,7 +126,7 @@

 #if defined( HB_BEOS )
     l->sem = create_sem( 1, "sem" );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_mutex_init( &l->mutex, NULL );
 #elif defined( HB_CYGWIN )
     l->mutex = CreateMutex( 0, FALSE, 0 );
@@ -141,7 +141,7 @@

 #if defined( HB_BEOS )
     delete_sem( l->sem );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_mutex_destroy( &l->mutex );
 #elif defined( HB_CYGWIN )
     CloseHandle( l->mutex );
@@ -161,7 +161,7 @@

 #if defined( HB_BEOS )
     c->thread = -1;
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_cond_init( &c->cond, NULL );
 #elif defined( HB_CYGWIN )
     c->event = CreateEvent( NULL, FALSE, FALSE, NULL );
@@ -175,7 +175,7 @@
     HBCond * c = *_c;

 #if defined( HB_BEOS )
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     pthread_cond_destroy( &c->cond );
 #elif defined( HB_CYGWIN )
     CloseHandle( c->event );
