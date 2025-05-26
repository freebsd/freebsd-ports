--- internal/vulncheck/packages.go.orig	2025-05-08 09:26:39 UTC
+++ internal/vulncheck/packages.go
@@ -34,7 +34,7 @@ func NewPackageGraph(goVersion string) *PackageGraph {
 	}
 
 	goRoot := ""
-	if out, err := exec.Command("go", "env", "GOROOT").Output(); err == nil {
+	if out, err := exec.Command("%%GO_CMD%%", "env", "GOROOT").Output(); err == nil {
 		goRoot = strings.TrimSpace(string(out))
 	}
 	stdlibModule := &packages.Module{
