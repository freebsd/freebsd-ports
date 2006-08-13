--- MP3Broadcaster/BroadcasterMain.cpp.orig	Sat Mar 12 08:24:54 2005
+++ MP3Broadcaster/BroadcasterMain.cpp	Sun Aug 13 00:37:12 2006
@@ -216,7 +216,7 @@
 
 struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__)
+#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&SignalEventHandler;
