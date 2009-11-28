--- src/load-graph.cpp.orig	2008-01-14 23:43:43.000000000 -0600
+++ src/load-graph.cpp	2008-01-14 23:44:15.000000000 -0600
@@ -412,7 +412,7 @@
 	  // e.g: ceil(100.5 KiB) = 101 KiB = 101 * 2**(1 * 10)
 	  //      where base10 = 1, coef10 = 101, pow2 = 16
 
-	  unsigned pow2 = std::floor(log2(new_max));
+	  unsigned pow2 = std::floor(log(new_max) / log(2));
 	  unsigned base10 = pow2 / 10;
 	  unsigned coef10 = std::ceil(new_max / double(1UL << (base10 * 10)));
 	  g_assert(new_max <= (coef10 * (1UL << (base10 * 10))));
