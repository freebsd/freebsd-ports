--- modules/gui/skins2/x11/x11_window.cpp.orig	2011-12-08 19:00:26.000000000 +0100
+++ modules/gui/skins2/x11/x11_window.cpp	2012-08-03 15:47:39.000000000 +0200
@@ -36,6 +36,7 @@
 #include "x11_factory.hpp"

 #include <assert.h>
+#include <limits.h>

 X11Window::X11Window( intf_thread_t *pIntf, GenericWindow &rWindow,
                       X11Display &rDisplay, bool dragDrop, bool playOnDrop,
