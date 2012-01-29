--- src/thread_base.cc.orig	2011-04-05 11:26:11.000000000 +0100
+++ src/thread_base.cc	2011-06-09 18:59:41.375670521 +0100
@@ -44,4 +44,5 @@
 #include <iostream>
 #include <signal.h>
+#include <unistd.h>
 #include <rak/error_number.h>
 #include <torrent/exceptions.h>
@@ -61,7 +61,7 @@
 
   static const unsigned int max_size = 32;
 
-  thread_queue_hack() { std::memset(this, 0, sizeof(thread_queue_hack)); }
+  thread_queue_hack() : m_lock(0) { std::memset(this, 0, sizeof(thread_queue_hack)); }
 
   void     lock()   { while (!__sync_bool_compare_and_swap(&m_lock, 0, 1)) usleep(0); }
   void     unlock() { __sync_bool_compare_and_swap(&m_lock, 1, 0); }
@@ -202,9 +203,14 @@
 void
 ThreadBase::interrupt_main_polling() {
-  do {
+  int sleep_length = 0;
+
+  while (ThreadBase::is_main_polling()) {
+    pthread_kill(main_thread->m_thread, SIGUSR1);
+
     if (!ThreadBase::is_main_polling())
       return;
-    
-    pthread_kill(main_thread->m_thread, SIGUSR1);
-  } while (1);
-}
+
+    usleep(sleep_length);
+    sleep_length = std::min(sleep_length + 50, 1000);
+  }
+}
