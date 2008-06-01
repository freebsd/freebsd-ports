--- StreamingLoadTool/StreamingLoadTool.cpp.orig	2008-06-01 18:20:48.000000000 +0900
+++ StreamingLoadTool/StreamingLoadTool.cpp	2008-06-01 18:31:35.000000000 +0900
@@ -135,7 +135,7 @@
 #ifndef __Win32__
 	struct sigaction act;
 	
-#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__)
+#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&sigcatcher;
