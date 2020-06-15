--- share/linearalgebra/matrixexp.lisp.orig	2019-10-21 03:38:58 UTC
+++ share/linearalgebra/matrixexp.lisp
@@ -138,8 +138,9 @@
 	   (print `(ratvars = ,$ratvars gcd = '$gcd algebraic = ,$algebraic))
 	   (print `(ratfac = ,$ratfac))
 	   (merror "Unable to find the spectrum")))
-   
-    (setq res ($fullratsimp (ncpower (sub (mult z ($ident n)) mat) -1) z))
+
+;; patch borrowed from SageMath
+    (setq res ($fullratsimp ($invert_by_lu (sub (mult z ($ident n)) mat) '$crering) z))
     (setq m (length sp))
     (dotimes (i m)
       (setq zi (nth i sp))
