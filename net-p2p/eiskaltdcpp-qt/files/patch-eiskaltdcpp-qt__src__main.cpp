--- ./eiskaltdcpp-qt/src/main.cpp.orig	2011-03-09 15:49:53.000000000 +0200
+++ ./eiskaltdcpp-qt/src/main.cpp	2011-03-09 15:50:14.000000000 +0200
@@ -58,8 +58,6 @@
 #include <signal.h>
 #include <execinfo.h>
 
-#include "extra/stacktrace.h"
-
 void installHandlers();
 
 #ifdef FORCE_XDG
@@ -214,8 +212,6 @@
         std::cout << QObject::tr("Cannot handle SIGPIPE").toStdString() << std::endl;
     }
 
-    signal(SIGSEGV, printBacktrace);
-
     std::cout << QObject::tr("Signal handlers installed.").toStdString() << std::endl;
 }
 
