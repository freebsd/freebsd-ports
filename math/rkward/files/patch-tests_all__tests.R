--- tests/all_tests.R.orig	2022-04-11 21:08:17 UTC
+++ tests/all_tests.R
@@ -2,10 +2,10 @@ require (rkwardtests)
 
 ## add your test suite files, to this vector:
 testsuites <- c (
-	"rkward_application_tests.R"
-	"import_export_plugins.R"
+	"rkward_application_tests.R",
+	"import_export_plugins.R",
 	"item_response_theory.R",
-	"analysis_plugins.R"
+	"analysis_plugins.R",
 	"distributions.R",
 	"plots.R",
 	"data_plugin_tests.R"
