--- numexpr/interpreter.cpp.orig	2018-07-12 17:49:43 UTC
+++ numexpr/interpreter.cpp
@@ -1269,7 +1269,7 @@ NumExpr_run(NumExprObject *self, PyObject *args, PyObj
             }
             Py_INCREF(dtypes[0]);
             a = (PyArrayObject *)PyArray_FromArray(operands[0], dtypes[0],
-                                        NPY_ARRAY_ALIGNED|NPY_ARRAY_UPDATEIFCOPY);
+                                        NPY_ARRAY_ALIGNED|NPY_ARRAY_WRITEBACKIFCOPY);
             if (a == NULL) {
                 goto fail;
             }
