--- src/plugins/python/accounttype.c.orig	2018-09-10 13:00:33 UTC
+++ src/plugins/python/accounttype.c
@@ -24,6 +24,10 @@
 
 #include <structmember.h>
 
+#if PY_MAJOR_VERSION == 3
+typedef int (*cmpfunc)(PyObject *, PyObject *);
+#endif
+
 typedef struct {
     PyObject_HEAD
     PrefsAccount *account;
@@ -38,7 +42,7 @@ static int Account_init(clawsmail_Accoun
 
 static void Account_dealloc(clawsmail_AccountObject* self)
 {
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static int Account_compare(clawsmail_AccountObject *obj1, clawsmail_AccountObject *obj2)
