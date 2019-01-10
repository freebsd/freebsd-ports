--- src/plugins/python/folderpropertiestype.c.orig	2019-01-09 18:47:36 UTC
+++ src/plugins/python/folderpropertiestype.c
@@ -38,7 +38,7 @@ static int FolderProperties_init(clawsma
 
 static void FolderProperties_dealloc(clawsmail_FolderPropertiesObject* self)
 {
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static PyObject* get_default_account(clawsmail_FolderPropertiesObject *self, void *closure)
