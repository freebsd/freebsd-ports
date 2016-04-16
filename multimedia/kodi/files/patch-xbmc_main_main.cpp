--- xbmc/main/main.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/main/main.cpp
@@ -28,6 +28,7 @@
 #ifdef TARGET_POSIX
 #include <sys/resource.h>
 #include <signal.h>
+#include <locale.h>
 #endif
 #if defined(TARGET_DARWIN_OSX)
   #include "Util.h"
@@ -35,7 +36,6 @@
   #ifdef HAS_SDL
     #include <SDL/SDL.h>
   #endif
-#include <locale.h>
 #endif
 #ifdef HAS_LIRC
 #include "input/linux/LIRC.h"
