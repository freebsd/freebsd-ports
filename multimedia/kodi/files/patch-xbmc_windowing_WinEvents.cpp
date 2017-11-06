--- xbmc/windowing/WinEvents.cpp.orig  2015-08-16 16:37:32 UTC
+++ xbmc/windowing/WinEvents.cpp
@@ -38,6 +38,10 @@
 #include "android/WinEventsAndroid.h"
 #define WinEventsType CWinEventsAndroid
 
+#elif defined(TARGET_FREEBSD) && defined(TARGET_RASPBERRY_PI)
+#include "WinEventsFreeBSD.h"
+#define WinEventsType CWinEventsFreeBSD
+
 #elif (defined(TARGET_FREEBSD) || defined(TARGET_LINUX)) && defined(HAS_SDL_WIN_EVENTS)
 #include "WinEventsSDL.h"
 #define WinEventsType CWinEventsSDL
