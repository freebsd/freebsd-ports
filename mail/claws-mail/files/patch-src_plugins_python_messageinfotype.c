--- src/plugins/python/messageinfotype.c.orig	2019-01-09 18:47:36 UTC
+++ src/plugins/python/messageinfotype.c
@@ -43,7 +43,7 @@ typedef struct {
 
 static void MessageInfo_dealloc(clawsmail_MessageInfoObject* self)
 {
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static int MessageInfo_init(clawsmail_MessageInfoObject *self, PyObject *args, PyObject *kwds)
