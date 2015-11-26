--- main.c.orig	2015-11-09 12:50:35.505718000 -0800
+++ main.c	2015-11-09 12:51:47.774569000 -0800
@@ -49,8 +49,6 @@
 #include "qt_ui.h"
 #endif
 
-#include "ncurses_ui.h"
-
 static void usage(void);
 static void about(void);
 void purge(void);
@@ -182,10 +180,6 @@
 		 argc, argv);
 #endif
 
-  } else {
-	
-    create_ncurses_ui(my_rc_defaults);
-
   }
 
   return 0;
