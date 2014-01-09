--- ./src/jagsabout.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsabout.h	2014-01-08 10:20:11.000000000 +0100
@@ -42,4 +42,6 @@
   
 };
 
+gint on_close(GtkWidget *widget, JagsAbout *about);
+
 #endif
