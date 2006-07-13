--- xview.c.orig	Thu Jul 13 12:10:02 2006
+++ xview.c	Thu Jul 13 12:11:30 2006
@@ -525,7 +525,7 @@
                       XV_HEIGHT,         16,
                       SERVER_IMAGE_BITS, help_cursor_array,
                       0) ;
-  help_cursor = xv_create(NULL, CURSOR,
+  help_cursor = xv_create(0, CURSOR,
                           CURSOR_XHOT,  0,
                           CURSOR_YHOT,  0,
                           CURSOR_OP,    PIX_SRC | PIX_DST,
@@ -590,7 +590,7 @@
 {
   int choice ;
 
-  choice = (int) menu_get(menu_item, MENU_VALUE,NULL) ;
+  choice = (int) menu_get(menu_item, MENU_VALUE, 0) ;
   if (choice) handle_menu_selection(curmenu, choice) ;
 }
 
