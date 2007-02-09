--- PlaylistBroadcaster.tproj/PlaylistBroadcaster.cpp.orig	Sat Mar 12 08:24:54 2005
+++ PlaylistBroadcaster.tproj/PlaylistBroadcaster.cpp	Sat Feb 10 04:04:32 2007
@@ -229,9 +229,9 @@
 
     sgProgramName = argv[0];
 #ifdef __Win32__
-    while ((anOption = getopt(argc, argv, "vhdcpbDtai:fe:" )) != EOF)
+    while ((anOption = getopt(argc, argv, "vhdcpbDtai:fe:" )) != -1)
 #else
-    while ((anOption = getopt(argc, argv, "vhdcpbDls:tai:fe:" )) != EOF)
+    while ((anOption = getopt(argc, argv, "vhdcpbDls:tai:fe:" )) != -1)
 #endif
     {
         
@@ -2077,7 +2077,7 @@
 
 struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__powerpc__) || defined (__sgi_cc__) || defined(__osf__) || defined(__hpux__)
+#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__powerpc__) || defined (__sgi_cc__) || defined(__osf__) || defined(__hpux__) || defined(__amd64__)
 	sigemptyset(&act.sa_mask);
 	act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&SignalEventHandler;
