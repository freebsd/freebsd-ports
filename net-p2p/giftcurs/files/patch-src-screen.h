--- src/screen.h.orig	Wed Nov  5 00:40:44 2003
+++ src/screen.h	Sun Feb  1 14:47:22 2004
@@ -71,6 +71,12 @@
 /* Used for "exporting" the items[] list. */
 const char *item_name(int);
 
+#include <wchar.h>
+#define __wchar_t
+#define __wint_t
+#define _WCHAR_T
+#define _WINT_T
+
 #if defined(USE_NCURSES) && !defined(RENAMED_NCURSES)
 # include <ncurses.h>
 #else
