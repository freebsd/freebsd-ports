--- vendor/golang.org/x/tools/internal/goroot/importcfg.go.orig	2025-05-08 09:33:18 UTC
+++ vendor/golang.org/x/tools/internal/goroot/importcfg.go
@@ -47,7 +47,7 @@ func PkgfileMap() (map[string]string, error) {
 func PkgfileMap() (map[string]string, error) {
 	once.Do(func() {
 		m := make(map[string]string)
-		output, err := exec.Command("go", "list", "-export", "-e", "-f", "{{.ImportPath}} {{.Export}}", "std", "cmd").Output()
+		output, err := exec.Command("%%GO_CMD%%", "list", "-export", "-e", "-f", "{{.ImportPath}} {{.Export}}", "std", "cmd").Output()
 		if err != nil {
 			stdlibPkgfileErr = err
 		}
