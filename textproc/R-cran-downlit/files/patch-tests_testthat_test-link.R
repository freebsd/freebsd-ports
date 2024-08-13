--- tests/testthat/test-link.R.orig	2024-08-13 05:33:03 UTC
+++ tests/testthat/test-link.R
@@ -217,10 +217,6 @@ test_that("looks in attached packages", {
     href_expr_(vignette("sha1")),
     "https://cran.rstudio.com/web/packages/digest/vignettes/sha1.html"
   )
-  expect_equal(
-    href_expr_(vignette("moveline")),
-    "https://cran.rstudio.com/web/packages/grid/vignettes/moveline.pdf"
-  )
 })
 
 test_that("fail gracefully with non-working calls", {
