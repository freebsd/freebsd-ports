
$FreeBSD$

--- src/display/window_log.cc.orig
+++ src/display/window_log.cc
@@ -69,7 +69,7 @@
 void
 WindowLog::receive_update() {
   iterator itr = find_older();
-  int h = std::min(std::distance(m_log->begin(), itr), 10);
+  int h = std::min(std::distance(m_log->begin(), itr), (ptrdiff_t) 10);
 
   if (h != m_minHeight) {
     set_active(h != 0);
