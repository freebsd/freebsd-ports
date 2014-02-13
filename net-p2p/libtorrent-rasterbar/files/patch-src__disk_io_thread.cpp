--- ./src/disk_io_thread.cpp.orig	2013-09-26 03:30:20.000000000 +0200
+++ ./src/disk_io_thread.cpp	2014-02-13 21:36:20.000000000 +0100
@@ -1765,7 +1765,7 @@
 #endif
 					TORRENT_ASSERT(j.buffer);
 					session_settings const* s = ((session_settings*)j.buffer);
-					TORRENT_ASSERT(s->cache_size >= 0);
+					TORRENT_ASSERT(s->cache_size >= -1);
 					TORRENT_ASSERT(s->cache_expiry > 0);
 
 #if defined TORRENT_WINDOWS
