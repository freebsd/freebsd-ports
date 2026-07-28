-- Declare explicit template instantiations for UnaryOpNode specializations so
-- they are defined only in libdwave-optimization.so (dwave/optimization/src/nodes/unaryop.cpp).
-- This prevents each Cython extension module from emitting its own type_info
-- copy, which breaks cross-DSO dynamic_cast on FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/unaryop.hpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/unaryop.hpp
@@ -96,4 +96,21 @@
 using SquareRootNode = UnaryOpNode<functional::square_root<double>>;
 using TanhNode = UnaryOpNode<functional::tanh<double>>;

+// Explicit instantiations live in dwave/optimization/src/nodes/unaryop.cpp so
+// that libdwave-optimization.so owns the canonical type_info objects. Tell
+// other translation units not to emit their own copies.
+extern template class UnaryOpNode<functional::abs<double>>;
+extern template class UnaryOpNode<functional::cos<double>>;
+extern template class UnaryOpNode<functional::exp<double>>;
+extern template class UnaryOpNode<functional::expit<double>>;
+extern template class UnaryOpNode<functional::log<double>>;
+extern template class UnaryOpNode<functional::logical<double>>;
+extern template class UnaryOpNode<functional::rint<double>>;
+extern template class UnaryOpNode<functional::sin<double>>;
+extern template class UnaryOpNode<functional::square<double>>;
+extern template class UnaryOpNode<functional::square_root<double>>;
+extern template class UnaryOpNode<functional::tanh<double>>;
+extern template class UnaryOpNode<std::negate<double>>;
+extern template class UnaryOpNode<std::logical_not<double>>;
+
 }  // namespace dwave::optimization
