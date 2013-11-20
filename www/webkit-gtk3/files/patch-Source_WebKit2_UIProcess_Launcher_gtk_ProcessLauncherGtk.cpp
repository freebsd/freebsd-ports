--- Source/WebKit2/UIProcess/Launcher/gtk/ProcessLauncherGtk.cpp.orig	2012-09-24 16:48:12.000000000 +0000
+++ Source/WebKit2/UIProcess/Launcher/gtk/ProcessLauncherGtk.cpp	2012-09-24 16:48:41.000000000 +0000
@@ -27,6 +27,7 @@
 #include "config.h"
 #include "ProcessLauncher.h"
 
+#include <sys/wait.h>
 #include "Connection.h"
 #include "ProcessExecutablePath.h"
 #include <WebCore/FileSystem.h>
