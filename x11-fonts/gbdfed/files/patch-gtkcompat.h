--- gtkcompat.h~	2010-04-16 09:39:05.000000000 -0500
+++ gtkcompat.h	2012-06-05 12:01:03.340069638 -0500
@@ -24,7 +24,7 @@
 
 #include <gtk/gtkversion.h>
 
-#if GTK_MAJOR_VERSION >= (2) && GTK_MINOR_VERSION >= (20)
+#if 0
 #define GTK_WIDGET_REALIZED gtk_widget_get_realized
 #define GTK_WIDGET_STATE gtk_widget_get_state
 #define GTK_WIDGET_HAS_FOCUS gtk_widget_has_focus
