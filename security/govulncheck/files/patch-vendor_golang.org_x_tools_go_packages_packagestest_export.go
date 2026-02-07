--- vendor/golang.org/x/tools/go/packages/packagestest/export.go.orig	2025-05-08 09:28:42 UTC
+++ vendor/golang.org/x/tools/go/packages/packagestest/export.go
@@ -37,7 +37,7 @@ the 'go list' command on the specified modules:
 		})
 		defer e.Cleanup()
 
-		cmd := exec.Command("go", "list", "gopher.example/...")
+		cmd := exec.Command("%%GO_CMD%%", "list", "gopher.example/...")
 		cmd.Dir = e.Config.Dir
 		cmd.Env = e.Config.Env
 		out, err := cmd.Output()
