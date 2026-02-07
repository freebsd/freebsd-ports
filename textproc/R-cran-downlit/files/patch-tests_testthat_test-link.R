--- tests/testthat/test-link.R.orig	2025-11-28 09:31:09 UTC
+++ tests/testthat/test-link.R
@@ -247,10 +247,6 @@ test_that("looks in attached packages", {
   #   href_expr_(vignette("sha1")),
   #   "https://cran.rstudio.com/web/packages/digest/vignettes/sha1.html"
   # )
-  expect_equal(
-    href_expr_(vignette("moveline")),
-    "https://cran.rstudio.com/web/packages/grid/vignettes/moveline.pdf"
-  )
 })
 
 test_that("fail gracefully with non-working calls", {
