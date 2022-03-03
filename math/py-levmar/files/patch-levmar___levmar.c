--- levmar/_levmar.c.orig	2019-10-23 16:15:35 UTC
+++ levmar/_levmar.c
@@ -15970,7 +15970,9 @@ static PyTypeObject __pyx_type_6levmar_7_levmar__LMFun
   sizeof(struct __pyx_obj_6levmar_7_levmar__LMFunc), /*tp_basicsize*/
   0, /*tp_itemsize*/
   __pyx_tp_dealloc_6levmar_7_levmar__LMFunc, /*tp_dealloc*/
+#if PY_VERSION_HEX < 0x03090000
   0, /*tp_print*/
+#endif
   0, /*tp_getattr*/
   0, /*tp_setattr*/
   #if PY_MAJOR_VERSION < 3
@@ -17179,7 +17181,9 @@ static int __pyx_pymod_exec__levmar(PyObject *__pyx_py
   __pyx_vtable_6levmar_7_levmar__LMFunc.eval_func = (void (*)(struct __pyx_obj_6levmar_7_levmar__LMFunc *, double *, double *, int, int))__pyx_f_6levmar_7_levmar_7_LMFunc_eval_func;
   __pyx_vtable_6levmar_7_levmar__LMFunc.eval_jacf = (void (*)(struct __pyx_obj_6levmar_7_levmar__LMFunc *, double *, double *, int, int))__pyx_f_6levmar_7_levmar_7_LMFunc_eval_jacf;
   if (PyType_Ready(&__pyx_type_6levmar_7_levmar__LMFunc) < 0) __PYX_ERR(0, 49, __pyx_L1_error)
+#if PY_VERSION_HEX < 0x03090000
   __pyx_type_6levmar_7_levmar__LMFunc.tp_print = 0;
+#endif
   if (__Pyx_SetVtable(__pyx_type_6levmar_7_levmar__LMFunc.tp_dict, __pyx_vtabptr_6levmar_7_levmar__LMFunc) < 0) __PYX_ERR(0, 49, __pyx_L1_error)
   if (PyObject_SetAttrString(__pyx_m, "_LMFunc", (PyObject *)&__pyx_type_6levmar_7_levmar__LMFunc) < 0) __PYX_ERR(0, 49, __pyx_L1_error)
   if (__Pyx_setup_reduce((PyObject*)&__pyx_type_6levmar_7_levmar__LMFunc) < 0) __PYX_ERR(0, 49, __pyx_L1_error)
