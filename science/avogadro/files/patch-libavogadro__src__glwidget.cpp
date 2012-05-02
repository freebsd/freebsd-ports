--- ./libavogadro/src/glwidget.cpp.orig	2011-04-25 05:22:18.000000000 +0000
+++ ./libavogadro/src/glwidget.cpp	2012-05-01 22:02:14.170695198 +0000
@@ -64,6 +64,8 @@
 #include <QMutex>
 #endif
 
+#include <GL/glu.h>
+
 #include <cstdio>
 #include <vector>
 #include <cstdlib>
