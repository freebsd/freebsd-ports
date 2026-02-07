--- eiskaltdcpp-qt/src/main.cpp.orig	2013-08-29 21:25:02.000000000 +0400
+++ eiskaltdcpp-qt/src/main.cpp	2014-08-16 10:25:44.000000000 +0400
@@ -73,7 +73,6 @@
 #include <unistd.h>
 #include <signal.h>
 #if !defined (__HAIKU__)
-#include <execinfo.h>
 
 #ifdef ENABLE_STACKTRACE
 #include "extra/stacktrace.h"
