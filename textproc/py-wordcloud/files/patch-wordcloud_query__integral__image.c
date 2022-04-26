--- wordcloud/query_integral_image.c.orig	2018-07-26 16:13:02 UTC
+++ wordcloud/query_integral_image.c
@@ -15445,7 +15445,9 @@ static PyTypeObject __pyx_type___pyx_array = {
   sizeof(struct __pyx_array_obj), /*tp_basicsize*/
   0, /*tp_itemsize*/
   __pyx_tp_dealloc_array, /*tp_dealloc*/
+#if PY_VERSION_HEX < 0x03090000
   0, /*tp_print*/
+#endif
   0, /*tp_getattr*/
   0, /*tp_setattr*/
   #if PY_MAJOR_VERSION < 3
@@ -15553,7 +15555,9 @@ static PyTypeObject __pyx_type___pyx_MemviewEnum = {
   sizeof(struct __pyx_MemviewEnum_obj), /*tp_basicsize*/
   0, /*tp_itemsize*/
   __pyx_tp_dealloc_Enum, /*tp_dealloc*/
+#if PY_VERSION_HEX < 0x03090000
   0, /*tp_print*/
+#endif
   0, /*tp_getattr*/
   0, /*tp_setattr*/
   #if PY_MAJOR_VERSION < 3
@@ -15803,7 +15807,9 @@ static PyTypeObject __pyx_type___pyx_memoryview = {
   sizeof(struct __pyx_memoryview_obj), /*tp_basicsize*/
   0, /*tp_itemsize*/
   __pyx_tp_dealloc_memoryview, /*tp_dealloc*/
+#if PY_VERSION_HEX < 0x03090000
   0, /*tp_print*/
+#endif
   0, /*tp_getattr*/
   0, /*tp_setattr*/
   #if PY_MAJOR_VERSION < 3
@@ -15930,7 +15936,9 @@ static PyTypeObject __pyx_type___pyx_memoryviewslice =
   sizeof(struct __pyx_memoryviewslice_obj), /*tp_basicsize*/
   0, /*tp_itemsize*/
   __pyx_tp_dealloc__memoryviewslice, /*tp_dealloc*/
+#if PY_VERSION_HEX < 0x03090000
   0, /*tp_print*/
+#endif
   0, /*tp_getattr*/
   0, /*tp_setattr*/
   #if PY_MAJOR_VERSION < 3
@@ -16519,13 +16527,17 @@ static int __Pyx_modinit_type_init_code(void) {
   /*--- Type init code ---*/
   __pyx_vtabptr_array = &__pyx_vtable_array;
   __pyx_vtable_array.get_memview = (PyObject *(*)(struct __pyx_array_obj *))__pyx_array_get_memview;
+#if PY_VERSION_HEX < 0x03090000
   if (PyType_Ready(&__pyx_type___pyx_array) < 0) __PYX_ERR(1, 104, __pyx_L1_error)
   __pyx_type___pyx_array.tp_print = 0;
+#endif
   if (__Pyx_SetVtable(__pyx_type___pyx_array.tp_dict, __pyx_vtabptr_array) < 0) __PYX_ERR(1, 104, __pyx_L1_error)
   if (__Pyx_setup_reduce((PyObject*)&__pyx_type___pyx_array) < 0) __PYX_ERR(1, 104, __pyx_L1_error)
   __pyx_array_type = &__pyx_type___pyx_array;
+#if PY_VERSION_HEX < 0x03090000
   if (PyType_Ready(&__pyx_type___pyx_MemviewEnum) < 0) __PYX_ERR(1, 278, __pyx_L1_error)
   __pyx_type___pyx_MemviewEnum.tp_print = 0;
+#endif
   if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type___pyx_MemviewEnum.tp_dictoffset && __pyx_type___pyx_MemviewEnum.tp_getattro == PyObject_GenericGetAttr)) {
     __pyx_type___pyx_MemviewEnum.tp_getattro = __Pyx_PyObject_GenericGetAttr;
   }
@@ -16539,8 +16551,10 @@ static int __Pyx_modinit_type_init_code(void) {
   __pyx_vtable_memoryview.setitem_indexed = (PyObject *(*)(struct __pyx_memoryview_obj *, PyObject *, PyObject *))__pyx_memoryview_setitem_indexed;
   __pyx_vtable_memoryview.convert_item_to_object = (PyObject *(*)(struct __pyx_memoryview_obj *, char *))__pyx_memoryview_convert_item_to_object;
   __pyx_vtable_memoryview.assign_item_from_object = (PyObject *(*)(struct __pyx_memoryview_obj *, char *, PyObject *))__pyx_memoryview_assign_item_from_object;
+#if PY_VERSION_HEX < 0x03090000
   if (PyType_Ready(&__pyx_type___pyx_memoryview) < 0) __PYX_ERR(1, 329, __pyx_L1_error)
   __pyx_type___pyx_memoryview.tp_print = 0;
+#endif
   if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type___pyx_memoryview.tp_dictoffset && __pyx_type___pyx_memoryview.tp_getattro == PyObject_GenericGetAttr)) {
     __pyx_type___pyx_memoryview.tp_getattro = __Pyx_PyObject_GenericGetAttr;
   }
@@ -16552,8 +16566,10 @@ static int __Pyx_modinit_type_init_code(void) {
   __pyx_vtable__memoryviewslice.__pyx_base.convert_item_to_object = (PyObject *(*)(struct __pyx_memoryview_obj *, char *))__pyx_memoryviewslice_convert_item_to_object;
   __pyx_vtable__memoryviewslice.__pyx_base.assign_item_from_object = (PyObject *(*)(struct __pyx_memoryview_obj *, char *, PyObject *))__pyx_memoryviewslice_assign_item_from_object;
   __pyx_type___pyx_memoryviewslice.tp_base = __pyx_memoryview_type;
+#if PY_VERSION_HEX < 0x03090000
   if (PyType_Ready(&__pyx_type___pyx_memoryviewslice) < 0) __PYX_ERR(1, 960, __pyx_L1_error)
   __pyx_type___pyx_memoryviewslice.tp_print = 0;
+#endif
   if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type___pyx_memoryviewslice.tp_dictoffset && __pyx_type___pyx_memoryviewslice.tp_getattro == PyObject_GenericGetAttr)) {
     __pyx_type___pyx_memoryviewslice.tp_getattro = __Pyx_PyObject_GenericGetAttr;
   }
