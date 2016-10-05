--- bwdist.cc.orig	2015-08-07 12:34:57 UTC
+++ bwdist.cc
@@ -538,7 +538,7 @@ Currently, only 2D images are supported.
   // Compute optional 'index to closest object pixel', only if requested
   if (nargout > 1)
     {
-      if (numel >= pow (2, 32))
+      if (numel >= pow (2., 32))
         retval(1) = calc_index<uint64NDArray> (bw, xdist, ydist);
       else
         retval(1) = calc_index<uint32NDArray> (bw, xdist, ydist);
