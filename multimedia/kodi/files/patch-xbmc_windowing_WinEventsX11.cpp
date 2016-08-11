--- xbmc/windowing/WinEventsX11.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/windowing/WinEventsX11.cpp
@@ -23,6 +23,7 @@
 
 #ifdef HAS_X11_WIN_EVENTS
 
+#include <locale.h>
 #include "WinEvents.h"
 #include "WinEventsX11.h"
 #include "Application.h"
