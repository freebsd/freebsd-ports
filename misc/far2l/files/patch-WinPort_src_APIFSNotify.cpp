--- WinPort/src/APIFSNotify.cpp.orig	2020-06-22 23:39:14 UTC
+++ WinPort/src/APIFSNotify.cpp
@@ -6,6 +6,7 @@
 #include <thread>
 #include <condition_variable>
 #if defined(__APPLE__) || defined(__FreeBSD__)
+# include <sys/types.h>
 # include <sys/event.h>
 # include <sys/time.h>
 #elif !defined(__CYGWIN__)
