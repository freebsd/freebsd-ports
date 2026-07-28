-- Declare explicit template instantiations for ReduceNode specializations so
-- they are defined only in libdwave-optimization.so (dwave/optimization/src/nodes/reduce.cpp).
-- This prevents each Cython extension module from emitting its own type_info
-- copy, which breaks cross-DSO dynamic_cast on FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/reduce.hpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/reduce.hpp
@@ -141,4 +141,14 @@
 using ProdNode = ReduceNode<std::multiplies<double>>;
 using SumNode = ReduceNode<std::plus<double>>;

+// Explicit instantiations live in dwave/optimization/src/nodes/reduce.cpp so
+// that libdwave-optimization.so owns the canonical type_info objects. Tell
+// other translation units not to emit their own copies.
+extern template class ReduceNode<functional::max<double>>;
+extern template class ReduceNode<functional::min<double>>;
+extern template class ReduceNode<std::logical_and<double>>;
+extern template class ReduceNode<std::logical_or<double>>;
+extern template class ReduceNode<std::multiplies<double>>;
+extern template class ReduceNode<std::plus<double>>;
+
 }  // namespace dwave::optimization
