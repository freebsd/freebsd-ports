--- movtar_play.c.orig	Tue Oct 16 00:22:46 2001
+++ movtar_play.c	Tue Oct 16 00:25:12 2001
@@ -9,8 +9,8 @@
 #include <signal.h>
 #include <string.h>
 
-#include <SDL/SDL.h>
-#include <SDL/SDL_timer.h>
+#include <SDL11/SDL.h>
+#include <SDL11/SDL_timer.h>
 
 #define JPEG_INTERNALS
 #include <jinclude.h>
