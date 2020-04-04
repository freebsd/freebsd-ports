Fix with Qt5-5.14

--- src/plugins/VerticalTabs/verticaltabsplugin.cpp.orig	2020-04-04 13:09:12 UTC
+++ src/plugins/VerticalTabs/verticaltabsplugin.cpp
@@ -30,6 +30,7 @@
 #include "../config.h"
 #include "desktopfile.h"
 
+#include <QFile>
 #include <QSettings>
 
 VerticalTabsPlugin::VerticalTabsPlugin()
