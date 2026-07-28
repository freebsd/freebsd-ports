-- Declare explicit template instantiations for NaryOpNode specializations so
-- they are defined only in libdwave-optimization.so (dwave/optimization/src/nodes/naryop.cpp).
-- This prevents each Cython extension module from emitting its own type_info
-- copy, which breaks cross-DSO dynamic_cast on FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/naryop.hpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/naryop.hpp
@@ -86,4 +86,12 @@
 using NaryMinimumNode = NaryOpNode<functional::min<double>>;
 using NaryMultiplyNode = NaryOpNode<std::multiplies<double>>;

+// Explicit instantiations live in dwave/optimization/src/nodes/naryop.cpp so
+// that libdwave-optimization.so owns the canonical type_info objects. Tell
+// other translation units not to emit their own copies.
+extern template class NaryOpNode<functional::max<double>>;
+extern template class NaryOpNode<functional::min<double>>;
+extern template class NaryOpNode<std::multiplies<double>>;
+extern template class NaryOpNode<std::plus<double>>;
+
 }  // namespace dwave::optimization
