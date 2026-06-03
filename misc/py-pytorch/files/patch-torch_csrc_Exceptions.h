--- torch/csrc/Exceptions.h.orig	2026-04-18 16:00:24 UTC
+++ torch/csrc/Exceptions.h
@@ -153,7 +153,10 @@ extern PyObject *THPException_FatalError, *THPExceptio
 
 // Throwing this exception means that the python error flags have been already
 // set and control should be immediately returned to the interpreter.
-struct python_error : public std::exception {
+// TORCH_PYTHON_API on the struct gives vtable/typeinfo default visibility so
+// they are exported from libtorch_python.so and can be matched across DSOs
+// (critical for FreeBSD libcxxrt which uses pointer-only RTTI comparison).
+struct TORCH_PYTHON_API python_error : public std::exception {
   python_error() = default;
 
   python_error(const python_error& other)
@@ -181,18 +184,12 @@ struct python_error : public std::exception {
   python_error& operator=(python_error&& other) = delete;
 
   // NOLINTNEXTLINE(bugprone-exception-escape)
-  ~python_error() override {
-    if (type || value || traceback) {
-      pybind11::gil_scoped_acquire gil;
-      Py_XDECREF(type);
-      Py_XDECREF(value);
-      Py_XDECREF(traceback);
-    }
-  }
+  // Non-inline: establishes key function so typeinfo is emitted only in
+  // Exceptions.cpp (with default visibility), enabling cross-DSO RTTI.
+  ~python_error() override;
 
-  const char* what() const noexcept override {
-    return message.c_str();
-  }
+  // Non-inline for the same reason as ~python_error().
+  const char* what() const noexcept override;
 
   void build_message() {
     // Ensure we have the GIL.
@@ -274,34 +271,31 @@ TORCH_PYTHON_API std::string processErrorMsg(std::stri
 
 TORCH_PYTHON_API std::string processErrorMsg(std::string str);
 
-// Abstract base class for exceptions which translate to specific Python types
-struct PyTorchError : public std::exception {
+// Abstract base class for exceptions which translate to specific Python types.
+// TORCH_PYTHON_API on the struct gives vtable/typeinfo default visibility so
+// they are exported from libtorch_python.so and can be matched across DSOs.
+struct TORCH_PYTHON_API PyTorchError : public std::exception {
   PyTorchError() = default;
   PyTorchError(std::string msg_) : msg(std::move(msg_)) {}
   virtual PyObject* python_type() = 0;
-  const char* what() const noexcept override {
-    return msg.c_str();
-  }
+  // Defined out-of-line to establish a key function.
+  const char* what() const noexcept override;
   std::string msg;
 };
 
 // Translates to Python TypeError
-struct TypeError : public PyTorchError {
-  TORCH_PYTHON_API TypeError() = default;
-  TORCH_PYTHON_API TypeError(std::string msg_)
-      : PyTorchError(std::move(msg_)) {}
+struct TORCH_PYTHON_API TypeError : public PyTorchError {
+  TypeError() = default;
+  TypeError(std::string msg_) : PyTorchError(std::move(msg_)) {}
   using PyTorchError::PyTorchError;
-  PyObject* python_type() override {
-    return PyExc_TypeError;
-  }
+  // Out-of-line to give TypeError its own key function for RTTI export.
+  PyObject* python_type() override;
 };
 
 // Translates to Python AttributeError
-struct AttributeError : public PyTorchError {
+struct TORCH_PYTHON_API AttributeError : public PyTorchError {
   using PyTorchError::PyTorchError;
-  PyObject* python_type() override {
-    return PyExc_AttributeError;
-  }
+  PyObject* python_type() override;
 };
 
 // ATen warning handler for Python
