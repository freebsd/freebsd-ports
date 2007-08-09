--- include/vlc_threads_funcs.h.orig	2007-08-08 14:53:27.000000000 +0200
+++ include/vlc_threads_funcs.h	2007-08-08 14:55:58.000000000 +0200
@@ -111,7 +111,7 @@
     i_result = pthread_mutex_lock( &p_mutex->mutex );
     if ( i_result )
     {
-        i_thread = (int)pthread_self();
+        i_thread = (intptr_t)pthread_self();
         psz_error = strerror(i_result);
     }
 
@@ -184,7 +184,7 @@
     i_result = pthread_mutex_unlock( &p_mutex->mutex );
     if ( i_result )
     {
-        i_thread = (int)pthread_self();
+        i_thread = (intptr_t)pthread_self();
         psz_error = strerror(i_result);
     }
 
@@ -322,7 +322,7 @@
     i_result = pthread_cond_signal( &p_condvar->cond );
     if ( i_result )
     {
-        i_thread = (int)pthread_self();
+        i_thread = (intptr_t)pthread_self();
         psz_error = strerror(i_result);
     }
 
@@ -512,7 +512,7 @@
 
     if ( i_result )
     {
-        i_thread = (int)pthread_self();
+        i_thread = (intptr_t)pthread_self();
         psz_error = strerror(i_result);
     }
 
