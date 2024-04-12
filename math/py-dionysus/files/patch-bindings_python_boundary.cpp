- workaround for https://github.com/mrzv/dionysus/issues/63

--- bindings/python/boundary.cpp.orig	2024-04-12 03:21:33 UTC
+++ bindings/python/boundary.cpp
@@ -68,7 +68,7 @@ PyMatrixFiltration coboundary(const PyFiltration& f)
                           return Entry(ee, f.index(e.index()));
                         }))
         {
-            m.column(n - 1 - x.index()).emplace_back(Entry { x.element(), n - 1 - i });
+            m.column(n - 1 - x.index()).emplace_back(Entry { x.element(), (unsigned int)(n - 1 - i) });
         }
         ++i;
     }
