--- filter/preview/display.h.orig	Fri Aug  9 10:41:59 2002
+++ filter/preview/display.h	Fri Aug  9 10:41:59 2002
@@ -39,9 +39,11 @@
 #endif // HAVE_LIBXV
 
 #if HAVE_SDL
-#include <SDL/SDL.h>
-#include <SDL/SDL_syswm.h>
+#include <SDL.h>
+#include <SDL_syswm.h>
 #endif // HAVE_SDL
+
+#include <glib.h>
 
 #if HAVE_GTK
 #include <gtk/gtk.h>
