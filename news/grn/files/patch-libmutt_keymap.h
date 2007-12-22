--- libmutt/keymap.h.orig	2007-12-20 19:31:26.000000000 +0100
+++ libmutt/keymap.h	2007-12-20 19:32:04.000000000 +0100
@@ -77,7 +77,7 @@
 /* dokey() records the last real key pressed  */
 extern int LastKey;
 
-extern struct mapping_t Menus[];
+extern struct mapping_t *Menus;
 
 struct binding_t
 {
