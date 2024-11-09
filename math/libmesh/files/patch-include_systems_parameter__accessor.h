--- include/systems/parameter_accessor.h.orig	2024-11-04 03:11:10 UTC
+++ include/systems/parameter_accessor.h
@@ -112,13 +112,14 @@ class ParameterProxy (public)
   /**
    * Setter: change the value of the parameter we access.
    */
+#if 0 // fix build with clang-19: https://github.com/libMesh/libmesh/issues/3991
   ParameterProxy & operator = (const ParameterProxy<T> & new_value) { _accessor.set(new_value.get()); }
 
   /**
    * Setter: change the value of the parameter we access.
    */
   ParameterProxy & operator = (const ConstParameterProxy<T> & new_value) { _accessor.set(new_value.get()); return *this; }
-
+#endif
   /**
    * Setter: change the value of the parameter we access.
    */
