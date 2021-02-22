--- geomGamma.cpp.orig	2021-02-22 04:26:32 UTC
+++ geomGamma.cpp
@@ -192,7 +192,7 @@ DEFUN_DLD (__levelset_geomGamma, args, nargout,
       const Matrix inout = args(4).matrix_value ();
 
       /* Extract and check the dimensions.  */
-      const unsigned nNodes = phi.nelem ();
+      const unsigned nNodes = phi.numel ();
       const unsigned nElem = getDimension (nodelist, -1, 4);
       const unsigned nBdryEl = getDimension (bdryInd, -1, 1);
       getDimension (edges, nBdryEl, 4);
