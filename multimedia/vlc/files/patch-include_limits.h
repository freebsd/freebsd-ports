diff --git a/modules/gui/skins2/x11/x11_factory.cpp b/modules/gui/skins2/x11/x11_factory.cpp
index 79fdcaa..a916cfa 100644
--- modules/gui/skins2/x11/x11_factory.cpp
+++ modules/gui/skins2/x11/x11_factory.cpp
@@ -28,6 +28,7 @@
 #include <dirent.h>
 #include <sys/stat.h>
 #include <X11/Xlib.h>
+#include <limits.h>
 
 #include "x11_factory.hpp"
 #include "x11_display.hpp"
diff --git a/modules/gui/skins2/x11/x11_window.cpp b/modules/gui/skins2/x11/x11_window.cpp
index 64fa4ae..e9e85de 100644
--- modules/gui/skins2/x11/x11_window.cpp
+++ modules/gui/skins2/x11/x11_window.cpp
@@ -25,6 +25,7 @@
 #ifdef X11_SKINS
 
 #include <X11/Xatom.h>
+#include <limits.h>
 
 #include "../src/generic_window.hpp"
 #include "../src/vlcproc.hpp"
