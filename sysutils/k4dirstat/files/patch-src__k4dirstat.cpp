--- src/k4dirstat.cpp.orig	2019-11-23 11:51:27 UTC
+++ src/k4dirstat.cpp
@@ -13,6 +13,7 @@
 #include "k4dirstat.h"
 #include "settings.h"
 
+#include <unistd.h>
 #include <QtGui/QDropEvent>
 #include <QtGui/QPainter>
 
