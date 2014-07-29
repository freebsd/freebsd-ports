--- X11/popnindex.h.orig	Sun Nov 11 20:24:37 2001
+++ X11/popnindex.h	Sun Feb  9 15:05:54 2003
@@ -53,7 +53,7 @@
 
 #include <stdio.h>
 #include "param.h"
-#include "xpm.h"
+#include <X11/xpm.h>
 
 extern void m_paste ();
 extern void m_cut ();
