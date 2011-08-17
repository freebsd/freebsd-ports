--- ./source4/auth/credentials/pycredentials.h.orig	2010-01-11 06:35:28.000000000 +0100
+++ ./source4/auth/credentials/pycredentials.h	2011-08-05 17:40:27.000000000 +0200
@@ -20,7 +20,7 @@
 #define _PYCREDENTIALS_H_
 
 #include "auth/credentials/credentials.h"
-#include "pytalloc.h"
+#include "lib/talloc/pytalloc.h"
 
 PyAPI_DATA(PyTypeObject) PyCredentials;
 #define PyCredentials_Check(py_obj) PyObject_TypeCheck(py_obj, &PyCredentials)
