--- RichString.c.orig
+++ RichString.c
@@ -13,7 +13,11 @@
 #include "debug.h"
 #include <assert.h>
 #ifdef HAVE_LIBNCURSESW
+#    ifdef HAVE_NCURSESW_CURSES_H
 #include <ncursesw/curses.h>
+#    else
+#include <curses.h>
+#    endif
 #else
 #include <curses.h>
 #endif
