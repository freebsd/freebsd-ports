--- include/deal.II/opencascade/manifold_lib.h.orig	2026-07-25 14:03:25 UTC
+++ include/deal.II/opencascade/manifold_lib.h
@@ -328,7 +328,7 @@ namespace OpenCASCADE
      * it points to the right one above.
      */
 #  if DEAL_II_OPENCASCADE_VERSION_GTE(7, 6, 0)
-    Handle_Adaptor3d_Curve curve;
+    opencascade::handle<Adaptor3d_Curve> curve;
 #  else
     Handle_Adaptor3d_HCurve curve;
 #  endif
