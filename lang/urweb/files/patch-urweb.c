--- src/c/urweb.c.orig	2012-03-29 08:09:43.000000000 -0700
+++ src/c/urweb.c	2012-04-04 00:55:17.000000000 -0700
@@ -160,12 +160,7 @@
 static unsigned n_clients;
 
 static pthread_mutex_t clients_mutex =
-    #ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
-        PTHREAD_RECURSIVE_MUTEX_INITIALIZER
-    #else
-        PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
-    #endif
-    ;
+PTHREAD_MUTEX_INITIALIZER;
 size_t uw_messages_max = SIZE_MAX;
 size_t uw_clients_max = SIZE_MAX;
 
