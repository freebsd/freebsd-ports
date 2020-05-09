--- ui/ui-curse.c.orig	2020-01-22 17:13:40 UTC
+++ ui/ui-curse.c
@@ -10,7 +10,7 @@
 #define _XOPEN_SOURCE_EXTENDED
 
 #include <locale.h>
-#include <ncursesw/curses.h>
+#include <curses.h>
 #include <stdio.h> /* this one contains the NULL definition */
 #include <string.h>
 
@@ -149,7 +149,7 @@ int ui_getkey(void) {
     case KEY_RIGHT:     return(0x14D);
     case KEY_UP:        return(0x148);
     case KEY_DOWN:      return(0x150);
-    case KEY_BACKSPACE: return(8);
+    case KEY_BACKSPACE: case 127: return(8);
     case KEY_ENTER:     return(13);
     case KEY_PPAGE:     return(0x149);  /* PAGEUP */
     case KEY_NPAGE:     return(0x151);  /* PGDOWN */
