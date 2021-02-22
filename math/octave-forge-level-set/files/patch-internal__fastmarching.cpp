--- internal_fastmarching.cpp.orig	2021-02-22 04:24:09 UTC
+++ internal_fastmarching.cpp
@@ -74,7 +74,7 @@ DEFUN_DLD (__levelset_internal_fastmarching, args, nar
         {
           const Array<octave_idx_type> idx = getOctaveIdx (c);
           assert (c.size () == D
-                  && static_cast<dimensionT> (idx.length ()) == D);
+                  && static_cast<dimensionT> (idx.numel ()) == D);
 
           if (domain(idx))
             {
@@ -99,7 +99,7 @@ DEFUN_DLD (__levelset_internal_fastmarching, args, nar
         {
           const Array<octave_idx_type> idx = getOctaveIdx (c);
           assert (c.size () == D
-                  && static_cast<dimensionT> (idx.length ()) == D);
+                  && static_cast<dimensionT> (idx.numel ()) == D);
 
           const Grid& constGrid(grid);
           const Entry* e = constGrid.get (c);
