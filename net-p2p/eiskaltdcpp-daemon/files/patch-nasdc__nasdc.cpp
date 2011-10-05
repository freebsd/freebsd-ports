--- ./nasdc/nasdc.cpp.orig	2011-03-08 19:47:12.000000000 +0200
+++ ./nasdc/nasdc.cpp	2011-03-10 19:49:48.000000000 +0200
@@ -23,7 +23,6 @@
 #ifndef _WIN32
 #include <syslog.h>
 #include <signal.h>
-#include "extra/stacktrace.h"
 #endif
 
 #ifdef CLI_DAEMON
@@ -237,9 +236,6 @@
     temp = (char *)NULL;
     prompt = "edcppd$ ";
 #endif
-#ifndef _WIN32
-    signal(SIGSEGV, printBacktrace);
-#endif
     while (bServerRunning) {
         Thread::sleep(1);
         #ifdef CLI_DAEMON
