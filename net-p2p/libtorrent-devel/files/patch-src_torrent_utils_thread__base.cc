--- src/torrent/utils/thread_base.cc.orig
+++ src/torrent/utils/thread_base.cc
@@ -88,6 +88,8 @@ thread_base::stop_thread_wait() {
 
 void
 thread_base::interrupt() {
+  int sleep_length = 0;
+
   __sync_fetch_and_or(&m_flags, flag_no_timeout);
 
   while (is_polling() && has_no_timeout()) {
@@ -96,7 +98,8 @@ thread_base::interrupt() {
     if (!(is_polling() && has_no_timeout()))
       return;
 
-    usleep(0);
+    usleep(sleep_length);
+    sleep_length = std::min(sleep_length + 50, 1000);
   }
 }
