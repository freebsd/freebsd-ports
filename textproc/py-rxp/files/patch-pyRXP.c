--- pyRXP.c.orig	Sat Oct 26 00:27:40 2002
+++ pyRXP.c	Tue Aug 14 16:43:48 2007
@@ -578,7 +578,8 @@
 
 static PyObject* pyRXPParser_parse(pyRXPParserObject* xself, PyObject* args, PyObject* kw)
 {
-	int			srcLen, i;
+	int			srcLen;
+	Py_ssize_t	i;
 	char		*src;
 	FILE16		*f;
 	InputSource source;
@@ -731,11 +732,12 @@
 static pyRXPParserObject* pyRXPParser(PyObject* module, PyObject* args, PyObject* kw)
 {
 	pyRXPParserObject* self;
-	int	i;
+	Py_ssize_t	i;
 
 	if(!PyArg_ParseTuple(args, ":Parser")) return NULL;
-	if(!(self = PyObject_NEW(pyRXPParserObject, &pyRXPParserType))) return NULL;
-	self->warnCB = self->eoCB = self->fourth = (void*)self->srcName = NULL;
+	self = PyObject_NEW(pyRXPParserObject, &pyRXPParserType);
+	if(!self) return NULL;
+	self->warnCB = self->eoCB = self->fourth = self->srcName = NULL;
 	if(!(self->srcName=PyString_FromString("[unknown]"))){
 		PyErr_SetString(moduleError,"Internal error, memory limit reached!");
 Lfree:	pyRXPParserFree(self);
