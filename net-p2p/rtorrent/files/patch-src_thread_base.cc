--- src/thread_base.cc.orig	2011-06-07 12:06:49.729114328 -0400
+++ src/thread_base.cc	2011-06-07 12:07:19.880080780 -0400
@@ -61,7 +61,7 @@
 
   static const unsigned int max_size = 32;
 
-  thread_queue_hack() { std::memset(m_queue, 0, sizeof(thread_queue_hack)); }
+  thread_queue_hack() : m_lock(0) { std::memset(m_queue, 0, sizeof(thread_queue_hack)); }
 
   void     lock()   { while (!__sync_bool_compare_and_swap(&m_lock, 0, 1)) usleep(0); }
   void     unlock() { __sync_bool_compare_and_swap(&m_lock, 1, 0); }
