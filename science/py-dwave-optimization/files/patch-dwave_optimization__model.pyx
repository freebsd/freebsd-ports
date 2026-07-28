-- Use the mangled C++ type name as the runtime type registry key instead of
-- std::type_index.  On FreeBSD/Clang libc++ compares type_info object addresses
-- by default, and the same class template instantiations are emitted into both
-- libdwave-optimization.so and each Cython extension module.  The resulting
-- distinct type_info objects for the same type cause registry lookups to fail,
-- producing "given pointer cannot be cast to a known node type".  Comparing
-- mangled type name strings works across DSO boundaries.

--- dwave/optimization/_model.pyx.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/_model.pyx
@@ -32,7 +32,7 @@
 from libcpp cimport bool
 from libcpp.memory cimport make_shared
 from libcpp.span cimport span
-from libcpp.typeindex cimport type_index
+from libcpp.string cimport string
 from libcpp.unordered_map cimport unordered_map
 from libcpp.utility cimport move
 from libcpp.vector cimport vector
@@ -65,17 +65,22 @@
 """A tuple of 2-tuples listing all serialization versions supported."""


-# Store a mapping from the type_index of each C++ Node type to the relevant
-# Cython class. We don't refcount the PyObject*s pointing to each class because
-# the lifespace of this map is identical to that of the type objects.
-cdef unordered_map[type_index, PyObject*] _cpp_type_to_python
+# Store a mapping from the mangled C++ type name of each Node type to the
+# relevant Cython class. We use the type name string rather than std::type_index
+# because libc++'s default type_info comparison compares object addresses, and
+# the same C++ class template instantiations are emitted into both
+# libdwave-optimization.so and the individual Cython extension modules, giving
+# distinct type_info objects for the same type across DSOs on FreeBSD/Clang.
+# We don't refcount the PyObject*s pointing to each class because the lifespan of
+# this map is identical to that of the type objects.
+cdef unordered_map[string, PyObject*] _cpp_type_to_python

 # Register a mapping between the given Cython class and C++ class.
 cdef void _register(object cls, const type_info& typeinfo):
     """Register a Python/Cython symbol to allow it to be created from a pointer
     via `symbol_from_ptr`.
     """
-    _cpp_type_to_python[type_index(typeinfo)] = <PyObject*>(cls)
+    _cpp_type_to_python[string(typeinfo.name())] = <PyObject*>(cls)


 cdef object symbol_from_ptr(_Graph model, cppNode* node_ptr):
@@ -86,7 +91,7 @@
         raise ValueError("cannot construct a Symbol from the given pointer")

     try:
-        cls = <object>_cpp_type_to_python.at(type_index(typeid(deref(node_ptr))))
+        cls = <object>_cpp_type_to_python.at(string(typeid(deref(node_ptr)).name()))
     except IndexError:
         # IndexError would be returned by .at()
         raise RuntimeError("given pointer cannot be cast to a known node type") from None
