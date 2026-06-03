--- numpy/core/include/numpy/ndarrayobject.h.orig	2024-02-05 21:17:48 UTC
+++ numpy/core/include/numpy/ndarrayobject.h
@@ -99,7 +99,7 @@ extern "C" {
 #define PyArray_FILLWBYTE(obj, val) memset(PyArray_DATA(obj), val, \
                                            PyArray_NBYTES(obj))
 #ifndef PYPY_VERSION
-#define PyArray_REFCOUNT(obj) (((PyObject *)(obj))->ob_refcnt)
+#define PyArray_REFCOUNT(obj) Py_REFCNT((PyObject *)(obj))
 #define NPY_REFCOUNT PyArray_REFCOUNT
 #endif
 #define NPY_MAX_ELSIZE (2 * NPY_SIZEOF_LONGDOUBLE)
