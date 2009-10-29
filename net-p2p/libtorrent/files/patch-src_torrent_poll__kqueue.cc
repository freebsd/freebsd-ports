--- src/torrent/poll_kqueue.cc.orig	2008-12-09 10:47:34.000000000 +0000
+++ src/torrent/poll_kqueue.cc	2008-12-09 10:48:10.000000000 +0000
@@ -52,6 +52,8 @@
 #include <sys/event.h>
 #include <sys/select.h>
 #include <sys/time.h>
+
+#include <assert.h>
 #endif
 
 namespace torrent {
@@ -113,7 +113,7 @@
   if (fd == -1)
     return NULL;
 
-  return new PollKQueue(fd, 1024, maxOpenSockets);
+  return new PollKQueue(fd, 16384, maxOpenSockets);
 }
 
 PollKQueue::PollKQueue(int fd, int maxEvents, int maxOpenSockets) :
