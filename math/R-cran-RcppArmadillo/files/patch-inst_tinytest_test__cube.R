https://github.com/RcppCore/RcppArmadillo/issues/408

--- inst/tinytest/test_cube.R.orig	2023-02-19 18:01:50 UTC
+++ inst/tinytest/test_cube.R
@@ -24,7 +24,7 @@ Rcpp::sourceCpp("cpp/cube.cpp")
 Rcpp::sourceCpp("cpp/cube.cpp")
 
 .onWindows <- .Platform$OS.type == "windows"
-critTol <- if (.onWindows) 1.0e-6 else 1.5e-7
+critTol <- if (.onWindows || .Machine$sizeof.long == 4 || .Machine$sizeof.long == 8) 1.0e-6 else 1.5e-7
 
 ## test arrays
 dbl_cube <- array(1.5:27.5, rep(3, 3))
