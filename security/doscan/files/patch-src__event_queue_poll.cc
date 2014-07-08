--- ./src/event_queue_poll.cc.orig	2014-07-08 13:37:17.446327398 +0200
+++ ./src/event_queue_poll.cc	2014-07-08 13:37:46.925961262 +0200
@@ -22,6 +22,7 @@
 
 #include <cerrno>
 #include <cstdio>
+#include <cstdlib>
 #include <unistd.h>
 
 void
