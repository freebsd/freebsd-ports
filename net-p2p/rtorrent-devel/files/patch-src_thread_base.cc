--- src/thread_base.cc.orig	2011-04-05 11:26:11.000000000 +0100
+++ src/thread_base.cc	2011-06-09 18:59:41.375670521 +0100
@@ -61,7 +61,7 @@
 
   static const unsigned int max_size = 32;
 
-  thread_queue_hack() { std::memset(this, 0, sizeof(thread_queue_hack)); }
+  thread_queue_hack() : m_lock(0) { std::memset(this, 0, sizeof(thread_queue_hack)); }
 
   void     lock()   { while (!__sync_bool_compare_and_swap(&m_lock, 0, 1)) usleep(0); }
   void     unlock() { __sync_bool_compare_and_swap(&m_lock, 1, 0); }
