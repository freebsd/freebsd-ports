--- lib/wnrtl.c	Fri May  6 13:17:39 2005
+++ lib/wnrtl.c	Wed Dec 21 00:21:04 2005
@@ -8,5 +8,5 @@
 #include "wn.h"
 
-static char *Id = "$Id: wnrtl.c,v 1.8 2005/01/27 17:33:54 wn Rel $";
+__FBSDID("$Id: wnrtl.c,v 1.8 2005/01/27 17:33:54 wn Rel $");
 
 /* Search code variables and flags */
@@ -43,6 +43,5 @@
    Default function provided in library returns -1 */
 
-int default_display_message(char *);
-int (*display_message)(char *) = default_display_message;
+int (*display_message)(const char *) = default_display_message;
 
 /*
