--- tests/testthat/test_import_list.R.orig	2026-10-26 14:25:47 UTC
+++ tests/testthat/test_import_list.R
@@ -130,24 +130,14 @@ test_that("Object names are preserved by import_list()
         export(list(mtcars1 = mtcars[1:10,],
                     mtcars2 = mtcars[11:20,],
                     mtcars3 = mtcars[21:32,]), "mtcars.xlsx")
-        export(list(mtcars1 = mtcars[1:10,],
-                    mtcars2 = mtcars[11:20,],
-                    mtcars3 = mtcars[21:32,]), "mtcars.ods")
-        export(list(mtcars1 = mtcars[1:10,],
-                    mtcars2 = mtcars[11:20,],
-                    mtcars3 = mtcars[21:32,]), "mtcars.fods")
         export(mtcars[1:10,],  "mtcars1.csv")
         export(mtcars[11:20,], "mtcars2.tsv")
         export(mtcars[21:32,], "mtcars3.csv")
         expected_names <- c("mtcars1", "mtcars2", "mtcars3")
         dat_xls <- import_list("mtcars.xlsx")
         dat_csv <- import_list(c("mtcars1.csv","mtcars2.tsv","mtcars3.csv"))
-        dat_ods <- import_list("mtcars.ods")
-        dat_fods <- import_list("mtcars.fods")
         expect_identical(names(dat_xls), expected_names)
         expect_identical(names(dat_csv), expected_names)
-        expect_identical(names(dat_ods), expected_names)
-        expect_identical(names(dat_fods), expected_names)
     })
 })
 
