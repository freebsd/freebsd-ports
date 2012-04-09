--- src/c/urweb.c.orig	Thu Mar 29 11:23:35 2012 -0400
+++ src/c/urweb.c	Sun Apr 08 13:47:57 2012 -0700
@@ -159,13 +159,7 @@
 static client **clients, *clients_free, *clients_used;
 static unsigned n_clients;
 
-static pthread_mutex_t clients_mutex =
-    #ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
-        PTHREAD_RECURSIVE_MUTEX_INITIALIZER
-    #else
-        PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
-    #endif
-    ;
+static pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
 size_t uw_messages_max = SIZE_MAX;
 size_t uw_clients_max = SIZE_MAX;
 
@@ -230,20 +224,23 @@
 }
 
 static const char begin_msgs[] = "Content-type: text/plain\r\n\r\n";
+static pthread_t pruning_thread;
+static int pruning_thread_initialized = 0;
 
 static client *find_client(unsigned id) {
   client *c;
-
-  pthread_mutex_lock(&clients_mutex);
+  int i_am_pruner = pruning_thread_initialized && pthread_equal(pruning_thread, pthread_self());
+
+  if (!i_am_pruner) pthread_mutex_lock(&clients_mutex);
 
   if (id >= n_clients) {
-    pthread_mutex_unlock(&clients_mutex);
+    if (!i_am_pruner) pthread_mutex_unlock(&clients_mutex);
     return NULL;
   }
 
   c = clients[id];
 
-  pthread_mutex_unlock(&clients_mutex);
+  if (!i_am_pruner) pthread_mutex_unlock(&clients_mutex);
   return c;
 }
 
@@ -3291,6 +3288,8 @@
   cutoff = time(NULL) - ctx->app->timeout;
 
   pthread_mutex_lock(&clients_mutex);
+  pruning_thread = pthread_self();
+  pruning_thread_initialized = 1;
 
   for (c = clients_used; c; c = next) {
     next = c->next;
