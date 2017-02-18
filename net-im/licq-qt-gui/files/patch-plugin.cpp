--- src/core/plugin.cpp.orig	2014-06-01 19:16:42 UTC
+++ src/core/plugin.cpp
@@ -31,6 +31,7 @@
 # include <QInternal>
 #include <KDE/KCmdLineArgs>
 #include <KDE/KMessage>
+#include <stdlib.h>
 #else
 # include <QStyleFactory>
 #endif
