--- playdv/display.h.orig	Sun Jun 24 13:06:30 2001
+++ playdv/display.h	Wed Nov 21 03:52:21 2001
@@ -38,8 +38,8 @@
 #endif // HAVE_LIBXV
 
 #if HAVE_SDL
-#include <SDL/SDL.h>
-#include <SDL/SDL_syswm.h>
+#include <SDL.h>
+#include <SDL_syswm.h>
 #endif // HAVE_SDL
 
 #if HAVE_GTK
