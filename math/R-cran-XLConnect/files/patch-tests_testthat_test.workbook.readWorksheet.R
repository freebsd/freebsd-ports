--- tests/testthat/test.workbook.readWorksheet.R.orig	2026-02-17 16:02:17 UTC
+++ tests/testthat/test.workbook.readWorksheet.R
@@ -308,10 +308,11 @@ test_that("handling of variable names works in XLS", {
   wb.xls <- loadWorkbook(test_path("resources/testWorkbookReadWorksheet.xls"), create = FALSE)
   target_var_names <- data.frame(
     `With whitespace` = 1:4,
-    `And some other funky characters: _=?^~!$@#%§` = letters[1:4],
+    funky = letters[1:4],
     check.names = FALSE,
     stringsAsFactors = FALSE
   )
+  names(target_var_names)[2] <- "And some other funky characters: _=?^~!$@#%\u00a7"
 
   # Check that reading worksheets with check.names = FALSE works
   res_xls_varnames <- readWorksheet(wb.xls, sheet = "VariableNames", header = TRUE, check.names = FALSE)
@@ -322,10 +323,11 @@ test_that("handling of variable names works in XLSX", 
   wb.xlsx <- loadWorkbook(test_path("resources/testWorkbookReadWorksheet.xlsx"), create = FALSE)
   target_var_names <- data.frame(
     `With whitespace` = 1:4,
-    `And some other funky characters: _=?^~!$@#%§` = letters[1:4],
+    funky = letters[1:4],
     check.names = FALSE,
     stringsAsFactors = FALSE
   )
+  names(target_var_names)[2] <- "And some other funky characters: _=?^~!$@#%\u00a7"
 
   # Check that reading worksheets with check.names = FALSE works
   res_xlsx_varnames <- readWorksheet(wb.xlsx, sheet = "VariableNames", header = TRUE, check.names = FALSE)
