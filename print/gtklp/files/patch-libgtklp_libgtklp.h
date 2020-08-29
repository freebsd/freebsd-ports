--- libgtklp/libgtklp.h.orig	2019-11-01 16:27:28 UTC
+++ libgtklp/libgtklp.h
@@ -80,7 +80,7 @@ void exitOnError(char *gerror1, char *gerror2, int exi
 void hello(GtkWidget * widget, gpointer data);
 void button_pad(GtkWidget * widget);
 #if GTK_MAJOR_VERSION != 1
-GtkWidget *progressBar;
+extern GtkWidget *progressBar;
 void setWindowDefaultIcons(void);
 #endif
 #endif				/* LIBGTKLP_H */
