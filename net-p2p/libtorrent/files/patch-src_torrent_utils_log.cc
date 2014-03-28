--- src/torrent/utils/log.cc.orig	2012-03-20 16:10:16.000000000 +0100
+++ src/torrent/utils/log.cc	2014-02-02 18:49:35.000000000 +0100
@@ -158,6 +158,7 @@
   va_list ap;
   unsigned int buffer_size = 4096;
   char buffer[buffer_size];
+  char *bufp = buffer;
   char* first = buffer;
 
   if (hash != NULL && subsystem != NULL) {
@@ -176,7 +177,7 @@
   pthread_mutex_lock(&log_mutex);
   std::for_each(m_first, m_last, tr1::bind(&log_slot::operator(),
                                            tr1::placeholders::_1,
-                                           buffer,
+                                           bufp,
                                            std::distance(buffer, first),
                                            std::distance(log_groups.begin(), this)));
   if (dump_data != NULL)
