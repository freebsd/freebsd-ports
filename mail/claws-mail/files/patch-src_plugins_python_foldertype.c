--- src/plugins/python/foldertype.c.orig	2019-01-09 18:47:36 UTC
+++ src/plugins/python/foldertype.c
@@ -40,7 +40,7 @@ typedef struct {
 static void Folder_dealloc(clawsmail_FolderObject* self)
 {
   Py_XDECREF(self->properties);
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static int Folder_init(clawsmail_FolderObject *self, PyObject *args, PyObject *kwds)
