https://github.com/rakshasa/libtorrent/issues/915

--- src/tracker/tracker_worker.cc.orig	2026-09-03 20:48:03 UTC
+++ src/tracker/tracker_worker.cc
@@ -2,6 +2,7 @@
 
 #include "tracker_worker.h"
 
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 #include "torrent/exceptions.h"
