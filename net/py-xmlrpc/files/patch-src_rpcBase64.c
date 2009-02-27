
$FreeBSD$

--- src/rpcBase64.c
+++ src/rpcBase64.c
@@ -239,7 +239,7 @@
 	if (bp->value) {
 		Py_DECREF(bp->value);
 	}
-	PyMem_DEL(bp);
+	PyObject_DEL(bp);
 }
 
 
