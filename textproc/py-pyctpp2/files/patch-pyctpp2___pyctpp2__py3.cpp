--- pyctpp2/_pyctpp2_py3.cpp.orig	2012-01-19 08:46:23 UTC
+++ pyctpp2/_pyctpp2_py3.cpp
@@ -4551,7 +4551,7 @@ static void __Pyx_RaiseArgtupleInvalid(
         more_or_less = "exactly";
     }
     PyErr_Format(PyExc_TypeError,
-                 "%s() takes %s %"PY_FORMAT_SIZE_T"d positional argument%s (%"PY_FORMAT_SIZE_T"d given)",
+                 "%s() takes %s %" PY_FORMAT_SIZE_T "d positional argument%s (%" PY_FORMAT_SIZE_T "d given)",
                  func_name, more_or_less, num_expected,
                  (num_expected == 1) ? "" : "s", num_found);
 }
@@ -4762,13 +4762,13 @@ bad:
 
 static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
     PyErr_Format(PyExc_ValueError,
-                 "need more than %"PY_FORMAT_SIZE_T"d value%s to unpack",
+                 "need more than %" PY_FORMAT_SIZE_T "d value%s to unpack",
                  index, (index == 1) ? "" : "s");
 }
 
 static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
     PyErr_Format(PyExc_ValueError,
-                 "too many values to unpack (expected %"PY_FORMAT_SIZE_T"d)", expected);
+                 "too many values to unpack (expected %" PY_FORMAT_SIZE_T "d)", expected);
 }
 
 static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected) {
