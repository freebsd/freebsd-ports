--- main.c.orig	2013-02-18 10:27:42.000000000 +0100
+++ main.c	2013-02-18 10:28:04.000000000 +0100
@@ -48,8 +48,6 @@
 #include "qt_ui.h"
 #endif
 
-#include "ncurses_ui.h"
-
 static void usage(void);
 static void about(void);
 void purge(void);
@@ -181,10 +179,6 @@
 		 argc, argv);
 #endif
 
-  } else {
-	
-    create_ncurses_ui(my_rc_defaults);
-
   }
 
   return 0;
