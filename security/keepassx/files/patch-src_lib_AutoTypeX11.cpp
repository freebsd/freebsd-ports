--- src/lib/AutoTypeX11.cpp.orig	2009-09-13 14:43:10 UTC
+++ src/lib/AutoTypeX11.cpp
@@ -23,6 +23,7 @@
 #include "mainwindow.h"
 #include "lib/HelperX11.h"
 #include <QX11Info>
+#include <time.h>
 
 #ifndef GLOBAL_AUTOTYPE
 AutoType* autoType = NULL;
