--- Server.tproj/main.cpp.orig	Wed Apr 27 21:21:14 2005
+++ Server.tproj/main.cpp	Sun Aug 13 00:39:07 2006
@@ -212,7 +212,7 @@
     //(void) ::signal(SIGPIPE, SIG_IGN);
     struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__)
+#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&sigcatcher;
