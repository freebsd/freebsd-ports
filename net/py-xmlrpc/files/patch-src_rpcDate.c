
$FreeBSD$

--- src/rpcDate.c
+++ src/rpcDate.c
@@ -75,7 +75,7 @@
 	if (dp->value) {
 		Py_DECREF(dp->value);
 	}
-	PyMem_DEL(dp);
+	PyObject_DEL(dp);
 }
 
 
