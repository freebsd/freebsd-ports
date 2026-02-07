--- internal_mesh.cpp.orig	2021-02-22 04:30:13 UTC
+++ internal_mesh.cpp
@@ -300,7 +300,7 @@ getInnerSegment (const octave_scalar_map& segs,
 
   assert (innerPts.empty ());
   const ColumnVector inners = segs.contents ("inners").column_vector_value ();
-  const unsigned nInners = inners.nelem ();
+  const unsigned nInners = inners.numel ();
   for (unsigned i = 0; i < nInners; ++i)
     innerPts.push_back (inners(nInners - i - 1) - 1);
 }
@@ -387,7 +387,7 @@ DEFUN_DLD (__levelset_internal_mesh, args, nargout,
         {
           const unsigned cur = bdryElems(i) - 1;
           const Cell cellSegs = bdryelSegs(i).cell_value ();
-          const unsigned nSegs = cellSegs.nelem ();
+          const unsigned nSegs = cellSegs.numel ();
 
           std::vector<octave_scalar_map> segs;
           indexArr endEdges;
