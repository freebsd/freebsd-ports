--- ./processwrapper.cc.orig	2013-09-12 13:03:02.450955685 +0400
+++ ./processwrapper.cc	2013-09-12 13:04:34.115949039 +0400
@@ -1,5 +1,6 @@
 #include "processwrapper.hh"
 
+#include <unistd.h>
 #include <QtCore>
 
 #ifdef Q_OS_WIN32
