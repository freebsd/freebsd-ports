--- src/dt_entry.h.orig	2023-04-11 01:15:28 UTC
+++ src/dt_entry.h
@@ -44,7 +44,7 @@ struct _dt_entry_handler {
 
      GByteArray* (*encode)(const char *val, int len);
      GByteArray* (*decode)(const char *val, int len);
-} dt_entry_handler;
+};
 
 /* Methods, only to be used by subclasses */
 GtkWidget *dt_entry_get_widget(int error_context,
