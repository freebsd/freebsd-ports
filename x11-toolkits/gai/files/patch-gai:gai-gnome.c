--- gai/gai-gnome.c.orig	Mon Mar 15 10:36:46 2004
+++ gai/gai-gnome.c	Mon Mar 15 10:37:15 2004
@@ -537,8 +537,8 @@
 void gai_gnome_about_show (void)
 {
     char *authors[3];
-    GAI_ENTER;
     GdkPixbuf *pixbuf;
+    GAI_ENTER;
 
     if (GAI.about!=NULL) 
     {
