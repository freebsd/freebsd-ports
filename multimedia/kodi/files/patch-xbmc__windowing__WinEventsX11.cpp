--- xbmc/windowing/WinEventsX11.cpp.orig	2015-04-13 10:40:08 UTC
+++ xbmc/windowing/WinEventsX11.cpp
@@ -23,6 +23,7 @@
 
 #ifdef HAS_X11_WIN_EVENTS
 
+#include <locale.h>
 #include "WinEvents.h"
 #include "WinEventsX11.h"
 #include "Application.h"
