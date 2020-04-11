--- lxqt-config-input/touchpaddevice.cpp.orig	2020-04-11 10:19:56 UTC
+++ lxqt-config-input/touchpaddevice.cpp
@@ -20,6 +20,7 @@
 
 #include <cmath>
 #include <QDebug>
+#include <QUrl>
 #include <QX11Info>
 #include <libudev.h>
 #include <LXQt/Settings>
