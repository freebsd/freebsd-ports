--- source/opencascade/manifold_lib.cc.orig	2026-07-25 14:03:25 UTC
+++ source/opencascade/manifold_lib.cc
@@ -67,7 +67,7 @@ namespace OpenCASCADE
      * not of topological dimension one.
      */
 #  if DEAL_II_OPENCASCADE_VERSION_GTE(7, 6, 0)
-    Handle_Adaptor3d_Curve
+    opencascade::handle<Adaptor3d_Curve>
     curve_adaptor(const TopoDS_Shape &shape)
     {
       Assert((shape.ShapeType() == TopAbs_WIRE) ||
@@ -109,7 +109,7 @@ namespace OpenCASCADE
     shape_length(const TopoDS_Shape &sh)
     {
 #  if DEAL_II_OPENCASCADE_VERSION_GTE(7, 6, 0)
-      Handle_Adaptor3d_Curve adapt = curve_adaptor(sh);
+      opencascade::handle<Adaptor3d_Curve> adapt = curve_adaptor(sh);
       return GCPnts_AbscissaPoint::Length(*adapt);
 #  else
       Handle_Adaptor3d_HCurve adapt = curve_adaptor(sh);
