--- Source/WebCore/plugins/gtk/PluginViewGtk.cpp.orig	2011-08-29 22:19:17.000000000 +0200
+++ Source/WebCore/plugins/gtk/PluginViewGtk.cpp	2011-10-14 13:45:50.000000000 +0200
@@ -68,6 +68,7 @@
 #endif
 #include <gtk/gtk.h>
 
+#define String XtStringType
 #if defined(XP_UNIX)
 #include "RefPtrCairo.h"
 #include "gtk2xtbin.h"
@@ -80,6 +81,7 @@
 #include "PluginMessageThrottlerWin.h"
 #include <gdk/gdkwin32.h>
 #endif
+#undef String
 
 using JSC::ExecState;
 using JSC::Interpreter;
