--- vendor/golang.org/x/tools/go/gcexportdata/gcexportdata.go.orig	2025-05-08 09:27:42 UTC
+++ vendor/golang.org/x/tools/go/gcexportdata/gcexportdata.go
@@ -87,7 +87,7 @@ func Find(importPath, srcDir string) (filename, path s
 // Deprecated: Use the higher-level API in golang.org/x/tools/go/packages,
 // which is more efficient.
 func Find(importPath, srcDir string) (filename, path string) {
-	cmd := exec.Command("go", "list", "-json", "-export", "--", importPath)
+	cmd := exec.Command("%%GO_CMD%%", "list", "-json", "-export", "--", importPath)
 	cmd.Dir = srcDir
 	out, err := cmd.Output()
 	if err != nil {
