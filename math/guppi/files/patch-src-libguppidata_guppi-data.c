--- src/libguppidata/guppi-data.c.orig	2007-12-13 15:31:26.000000000 +0100
+++ src/libguppidata/guppi-data.c	2007-12-13 15:32:13.000000000 +0100
@@ -1079,8 +1079,6 @@
 static void
 guppi_data_class_init (GuppiDataClass *klass)
 {
-  static void build_menu (GuppiData *, GtkMenu *, gpointer);
-
   GtkObjectClass *object_class = (GtkObjectClass *) klass;
 
   parent_class = gtk_type_class (GTK_TYPE_OBJECT);
