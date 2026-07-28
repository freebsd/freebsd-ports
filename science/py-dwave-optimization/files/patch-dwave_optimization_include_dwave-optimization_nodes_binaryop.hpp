-- Declare explicit template instantiations for BinaryOpNode specializations so
-- they are defined only in libdwave-optimization.so (dwave/optimization/src/nodes/binaryop.cpp).
-- Without this, each Cython extension module that creates a binary-op node
-- instantiates its own copy of the class template, producing a distinct type_info
-- object for the same type.  libc++'s default type_info comparison then treats
-- those copies as different types and cross-DSO dynamic_cast fails on
-- FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/binaryop.hpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/binaryop.hpp
@@ -106,4 +106,23 @@
 using SubtractNode = BinaryOpNode<std::minus<double>>;
 using XorNode = BinaryOpNode<functional::logical_xor<double>>;

+// Explicit instantiations live in dwave/optimization/src/nodes/binaryop.cpp so
+// that libdwave-optimization.so owns the canonical type_info objects. Tell
+// other translation units (especially the Cython extension modules) not to
+// emit their own copies, which would break cross-DSO dynamic_cast on
+// FreeBSD/Clang.
+extern template class BinaryOpNode<std::plus<double>>;
+extern template class BinaryOpNode<std::logical_and<double>>;
+extern template class BinaryOpNode<std::divides<double>>;
+extern template class BinaryOpNode<std::equal_to<double>>;
+extern template class BinaryOpNode<std::less_equal<double>>;
+extern template class BinaryOpNode<functional::max<double>>;
+extern template class BinaryOpNode<functional::min<double>>;
+extern template class BinaryOpNode<functional::modulus<double>>;
+extern template class BinaryOpNode<std::multiplies<double>>;
+extern template class BinaryOpNode<std::logical_or<double>>;
+extern template class BinaryOpNode<functional::safe_divides<double>>;
+extern template class BinaryOpNode<std::minus<double>>;
+extern template class BinaryOpNode<functional::logical_xor<double>>;
+
 }  // namespace dwave::optimization
