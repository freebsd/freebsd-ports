--- torch/csrc/Exceptions.cpp.orig	2026-04-18 16:00:24 UTC
+++ torch/csrc/Exceptions.cpp
@@ -11,6 +11,31 @@
 
 #include <c10/util/StringUtil.h>
 
+// Out-of-line definitions for python_error, PyTorchError, TypeError, AttributeError.
+// These establish key functions so that vtables/typeinfo are emitted only here
+// (in libtorch_python.so) and exported with default visibility, enabling
+// correct cross-DSO RTTI matching on FreeBSD and other ELF platforms.
+python_error::~python_error() {
+  if (type || value || traceback) {
+    pybind11::gil_scoped_acquire gil;
+    Py_XDECREF(type);
+    Py_XDECREF(value);
+    Py_XDECREF(traceback);
+  }
+}
+const char* python_error::what() const noexcept {
+  return message.c_str();
+}
+const char* torch::PyTorchError::what() const noexcept {
+  return msg.c_str();
+}
+PyObject* torch::TypeError::python_type() {
+  return PyExc_TypeError;
+}
+PyObject* torch::AttributeError::python_type() {
+  return PyExc_AttributeError;
+}
+
 PyObject *THPException_FatalError, *THPException_LinAlgError,
     *THPException_OutOfMemoryError, *THPException_DistError,
     *THPException_DistBackendError, *THPException_DistNetworkError,
