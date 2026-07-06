--- tests/testthat/test.workbook.readNamedRegion.R.orig	2026-02-17 16:02:17 UTC
+++ tests/testthat/test.workbook.readNamedRegion.R
@@ -108,10 +108,11 @@ test_that("test.workbook.readNamedRegion", {
   expect_equal(res, target)
   target <- data.frame(
     `With whitespace` = 1:4,
-    `And some other funky characters: _=?^~!$@#%§` = letters[1:4],
+    funky = letters[1:4],
     check.names = FALSE,
     stringsAsFactors = FALSE
   )
+  names(target)[2] <- "And some other funky characters: _=?^~!$@#%\u00a7"
   # Check that reading named regions with check.names = FALSE works (*.xls)
   res <- readNamedRegion(wb.xls, name = "VariableNames", header = TRUE, check.names = FALSE)
   expect_equal(res, target)
