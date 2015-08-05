--- src/widget-helper.c.orig	2015-08-05 09:16:34.803154000 +0200
+++ src/widget-helper.c	2015-08-05 09:16:59.890589000 +0200
@@ -2404,7 +2404,7 @@
 LIVES_INLINE boolean lives_label_set_halignment(LiVESLabel *label, float yalign) {
 #ifdef GUI_GTK
 #if GTK_CHECK_VERSION(3,16,0)
-  gtk_label_set_y_align(label,yalign);
+  gtk_label_set_yalign(label,yalign);
 #else
   gtk_misc_set_alignment(GTK_MISC(label),0.,yalign);
 #endif
