--- Include/numarray/nummacro.h.orig	Fri Nov 18 20:42:15 2005
+++ Include/numarray/nummacro.h	Fri Nov 18 20:43:33 2005
@@ -24,7 +24,11 @@
 				     int n_outs, PyObject*outs[]);
 typedef struct {
 	PyObject_HEAD
+#ifdef __cplusplus
+	PyObject *operator_;         /* ufunc name */
+#else
 	PyObject *operator;          /* ufunc name */
+#endif
         PyObject *identity;          /* identity value, e.g. 0 for + or 1 for * */
         int   n_inputs, n_outputs;
         _ufunc_function call;
