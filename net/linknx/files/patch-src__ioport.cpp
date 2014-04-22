--- ./src/ioport.cpp.orig	2011-03-08 22:20:17.000000000 +0100
+++ ./src/ioport.cpp	2014-04-22 19:17:42.208791119 +0200
@@ -21,6 +21,7 @@
 #include <iomanip>
 #include "ioport.h"
 #include <fcntl.h>
+#include <unistd.h>
 
 Logger& IOPort::logger_m(Logger::getInstance("IOPort"));
 Logger& RxThread::logger_m(Logger::getInstance("RxThread"));
