--- menu.c.orig	2005-10-25 22:04:01 UTC
+++ menu.c
@@ -29,11 +29,13 @@
 #include "help.h"
 
 #define MENU_LINES 12
-#define MENU_COLS  38
+#define MENU_COLS  45
 
 #define MENU_CONTENTS \
                     "{[h]} online help\n" \
 		    "{[r]} rename machine\n" \
+                    "{[o]} toggle tag all machines (live only)\n" \
+                    "{[O]} toggle tag all machines (live & dead)\n" \
                     "{[t]} tag all machines (live only)\n" \
                     "{[T]} tag all machines (live & dead)\n" \
                     "{[u]} untag all machines\n" \
@@ -100,6 +102,8 @@ void menu_show() {
                 }
 
                 break;
+      case 'o': machmgr_toggle_tag_all(true); break;
+      case 'O': machmgr_toggle_tag_all(false); break;
       case 't': machmgr_tag_all(true); break;
       case 'T': machmgr_tag_all(false); break;
       case 'u': machmgr_untag_all(); break;
