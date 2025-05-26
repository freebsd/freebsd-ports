--- internal/buildinfo/additions_scan_test.go.orig	2025-05-08 09:20:20 UTC
+++ internal/buildinfo/additions_scan_test.go
@@ -145,7 +145,7 @@ func Vuln() {
 			})
 			defer e.Cleanup()
 
-			cmd := exec.Command("go", "build", "-o", "entry")
+			cmd := exec.Command("%%GO_CMD%%", "build", "-o", "entry")
 			cmd.Dir = e.Config.Dir
 			cmd.Env = e.Config.Env
 			out, err := cmd.CombinedOutput()
