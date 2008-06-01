--- PlaylistBroadcaster.tproj/PlaylistBroadcaster.cpp.orig	2008-05-06 08:29:00.000000000 +0900
+++ PlaylistBroadcaster.tproj/PlaylistBroadcaster.cpp	2008-06-01 18:07:58.000000000 +0900
@@ -231,7 +231,7 @@
 #ifdef __Win32__
     while ((anOption = getopt(argc, argv, "vhdcpbDtai:fe:" )) != EOF)
 #else
-    while ((anOption = getopt(argc, argv, "vhdcpbDls:tai:fe:" )) != EOF)
+    while ((anOption = getopt(argc, argv, "vhdcpbDls:tai:fe:" )) != -1)
 #endif
     {
         
@@ -2082,7 +2082,7 @@
 
 struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__powerpc__) || defined (__sgi_cc__) || defined(__osf__) || defined(__hpux__)
+#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__powerpc__) || defined (__sgi_cc__) || defined(__osf__) || defined(__hpux__) || defined(__amd64__)
 	sigemptyset(&act.sa_mask);
 	act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&SignalEventHandler;
