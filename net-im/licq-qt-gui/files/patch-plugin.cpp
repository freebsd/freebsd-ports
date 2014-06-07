--- src/core/plugin.cpp.orig	2014-06-01 21:16:42.000000000 +0200
+++ src/core/plugin.cpp	2014-06-06 22:08:35.000000000 +0200
@@ -31,6 +31,7 @@
 # include <QInternal>
 #include <KDE/KCmdLineArgs>
 #include <KDE/KMessage>
+#include <stdlib.h>
 #else
 # include <QStyleFactory>
 #endif
