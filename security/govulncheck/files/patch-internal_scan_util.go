--- internal/scan/util.go.orig	1979-11-30 00:00:00 UTC
+++ internal/scan/util.go
@@ -50,7 +50,7 @@ func gomodExists(dir string) bool {
 }
 
 func gomodExists(dir string) bool {
-	cmd := exec.Command("go", "env", "GOMOD")
+	cmd := exec.Command("%%GO_CMD%%", "env", "GOMOD")
 	cmd.Dir = dir
 	out, err := cmd.Output()
 	output := strings.TrimSpace(string(out))
