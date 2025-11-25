--- src/mainwindow.cpp.orig	2025-11-25 16:33:26 UTC
+++ src/mainwindow.cpp
@@ -46,6 +46,8 @@ $END_LICENSE */
 #include "view.h"
 #include "zoomableui.h"
 
+#include <iostream>
+
 #if defined(APP_MAC_SEARCHFIELD) && !defined(APP_MAC_QMACTOOLBAR)
 #include "searchlineedit_mac.h"
 #else
