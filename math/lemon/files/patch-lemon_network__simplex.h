-- Guard the NetworkSimplex class against the MAX(a,b) macro defined by FreeBSD system
-- headers via <sys/param.h>. LEMON uses MAX as a member variable name; the macro
-- expansion corrupts the constructor initializer list in C++20 code.
-- Uses #pragma push_macro/pop_macro, supported by GCC, Clang and MSVC.

--- lemon/network_simplex.h.orig
+++ lemon/network_simplex.h
@@ -71,6 +71,8 @@
   /// \note %NetworkSimplex provides five different pivot rule
   /// implementations, from which the most efficient one is used
   /// by default. For more information, see \ref PivotRule.
+#pragma push_macro("MAX")
+#undef MAX
   template <typename GR, typename V = int, typename C = V>
   class NetworkSimplex
   {
@@ -1651,6 +1653,7 @@
     }
 
   }; //class NetworkSimplex
+#pragma pop_macro("MAX")
 
   ///@}
 
