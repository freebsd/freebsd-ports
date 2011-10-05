--- ./eiskaltdcpp-gtk/src/wulfor.cc.orig	2011-03-10 16:43:57.000000000 +0200
+++ ./eiskaltdcpp-gtk/src/wulfor.cc	2011-03-10 16:44:22.000000000 +0200
@@ -37,7 +37,6 @@
 #define GUI_PACKAGE "eiskaltdcpp-gtk"
 
 #include "VersionGlobal.h"
-#include "extra/stacktrace.h"
 
 void printHelp()
 {
@@ -135,7 +134,6 @@
     g_set_application_name("EiskaltDC++ Gtk");
 
     signal(SIGPIPE, SIG_IGN);
-    signal(SIGSEGV, printBacktrace);
 
     WulforSettingsManager::newInstance();
     WulforManager::start(argc, argv);
