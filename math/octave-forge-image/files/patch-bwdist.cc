--- bwdist.cc-orig	2014-03-03 03:07:22.000000000 +0000
+++ bwdist.cc	2014-03-03 03:07:36.000000000 +0000
@@ -530,7 +530,7 @@
   // Compute optional 'index to closest object pixel', only if requested
   if (nargout > 1)
     {
-      if (numel >= pow (2, 32))
+      if (numel >= pow (2., 32))
         retval(1) = calc_index<uint64NDArray> (bw, xdist, ydist);
       else
         retval(1) = calc_index<uint32NDArray> (bw, xdist, ydist);
