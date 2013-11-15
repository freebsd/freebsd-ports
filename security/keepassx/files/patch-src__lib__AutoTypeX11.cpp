--- ./src/lib/AutoTypeX11.cpp.orig	2009-09-13 14:43:10.000000000 +0000
+++ ./src/lib/AutoTypeX11.cpp	2013-09-21 15:37:54.600146755 +0000
@@ -23,6 +23,7 @@
 #include "mainwindow.h"
 #include "lib/HelperX11.h"
 #include <QX11Info>
+#include <time.h>
 
 #ifndef GLOBAL_AUTOTYPE
 AutoType* autoType = NULL;
