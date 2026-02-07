--- src/load-graph.cpp.orig	2023-09-02 21:02:13 UTC
+++ src/load-graph.cpp
@@ -700,7 +700,7 @@ net_scale (LoadGraph *graph,
       // e.g: ceil(100.5 KiB) = 101 KiB = 101 * 2**(1 * 10)
       //      where base10 = 1, coef10 = 101, pow2 = 16
 
-      guint64 pow2 = std::floor (log2 (new_max));
+      guint64 pow2 = std::floor (log (new_max) / log (2));
       guint64 base10 = pow2 / 10.0;
       guint64 coef10 = std::ceil (new_max / double(G_GUINT64_CONSTANT (1) << (base10 * 10)));
       g_assert (new_max <= (coef10 * (G_GUINT64_CONSTANT (1) << (base10 * 10))));
