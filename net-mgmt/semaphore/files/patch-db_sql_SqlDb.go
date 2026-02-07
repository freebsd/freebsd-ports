--- db/sql/SqlDb.go.orig	2022-02-24 18:36:46 UTC
+++ db/sql/SqlDb.go
@@ -28,7 +28,7 @@ create table ` + "`migrations`" + ` (
 	` + "`notes`" + ` text null
 );
 `
-var dbAssets = packr.NewBox("./migrations")
+var dbAssets = packr.NewBox("%%DATADIR%%")
 
 func containsStr(arr []string, str string) bool {
 	for _, a := range arr {
