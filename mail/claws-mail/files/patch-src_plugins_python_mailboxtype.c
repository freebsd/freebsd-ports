--- src/plugins/python/mailboxtype.c.orig	2019-01-09 18:47:36 UTC
+++ src/plugins/python/mailboxtype.c
@@ -41,7 +41,7 @@ static int Mailbox_init(clawsmail_Mailbo
 static void Mailbox_dealloc(clawsmail_MailboxObject* self)
 {
   self->folder = NULL;
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static PyObject* Mailbox_str(clawsmail_MailboxObject *self)
