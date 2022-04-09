--- ../inst/vfzero.m.orig	2022-04-08 22:30:39.255870000 -0500
+++ ../inst/vfzero.m	2022-04-08 22:30:55.406374000 -0500
@@ -282,7 +282,7 @@
 				# fun() might expect full-length
 				# argument
       fval(idx, 1) = fc(idx, 1) = fun (c)(:)(idx, 1);
-      niter ++; nfev ++;
+      niter++; nfev++;
     endif
 
     ## Modification 2: skip inverse cubic interpolation if
