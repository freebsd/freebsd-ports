--- topaz/objectlist.h.orig	Wed Dec  4 23:02:26 2002
+++ topaz/objectlist.h	Fri Dec 27 04:41:21 2002
@@ -24,6 +24,10 @@
 #if !defined(__objectlist_h)
 #define __objectlist_h
 
+#include <string>
+
+using namespace std;
+
 #include "topazcurses.h"
 int objectlist(WINDOW *win, int mode, string *objtype);
 
