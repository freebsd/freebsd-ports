--- src/nautilus-python.c.orig	2020-09-13 15:42:41 UTC
+++ src/nautilus-python.c
@@ -22,6 +22,7 @@
 #endif
 
 #include <Python.h>
+#define NO_IMPORT_PYGOBJECT //To avoid a multiple definition, nautilus-python-object.c also includes and does the import.
 #include <pygobject.h>
 #include <gmodule.h>
 #include <gtk/gtk.h>
@@ -41,6 +42,17 @@ static gboolean nautilus_python_init_python(void);
 
 static GArray *all_types = NULL;
 
+PyTypeObject *_PyGtkWidget_Type;
+PyTypeObject *_PyNautilusColumn_Type;
+PyTypeObject *_PyNautilusColumnProvider_Type;
+PyTypeObject *_PyNautilusInfoProvider_Type;
+PyTypeObject *_PyNautilusLocationWidgetProvider_Type;
+PyTypeObject *_PyNautilusMenu_Type;
+PyTypeObject *_PyNautilusMenuItem_Type;
+PyTypeObject *_PyNautilusMenuProvider_Type;
+PyTypeObject *_PyNautilusPropertyPage_Type;
+PyTypeObject *_PyNautilusPropertyPageProvider_Type;
+PyTypeObject *_PyNautilusOperationHandle_Type;
 
 static inline gboolean 
 np_init_pygobject(void) {
