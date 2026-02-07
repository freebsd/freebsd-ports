--- vendor/golang.org/x/tools/internal/testenv/testenv.go.orig	2025-05-08 09:30:00 UTC
+++ vendor/golang.org/x/tools/internal/testenv/testenv.go
@@ -115,7 +115,7 @@ func HasTool(tool string) error {
 				checkGoBuild.err = err
 				return
 			}
-			cmd := exec.Command("go", "build", "-o", os.DevNull, mainGo)
+			cmd := exec.Command("%%GO_CMD%%", "build", "-o", os.DevNull, mainGo)
 			cmd.Dir = dir
 			if out, err := cmd.CombinedOutput(); err != nil {
 				if len(out) > 0 {
@@ -145,7 +145,7 @@ func cgoEnabled(bypassEnvironment bool) (bool, error) 
 }
 
 func cgoEnabled(bypassEnvironment bool) (bool, error) {
-	cmd := exec.Command("go", "env", "CGO_ENABLED")
+	cmd := exec.Command("%%GO_CMD%%", "env", "CGO_ENABLED")
 	if bypassEnvironment {
 		cmd.Env = append(append([]string(nil), os.Environ()...), "CGO_ENABLED=")
 	}
@@ -444,7 +444,7 @@ func findGOROOT() (string, error) {
 			return
 		}
 
-		cmd := exec.Command("go", "env", "GOROOT")
+		cmd := exec.Command("%%GO_CMD%%", "env", "GOROOT")
 		out, err := cmd.Output()
 		if err != nil {
 			gorootErr = fmt.Errorf("%v: %v", cmd, err)
@@ -480,7 +480,7 @@ func NeedsLocalXTools(t testing.TB) {
 
 	NeedsTool(t, "go")
 
-	cmd := Command(t, "go", "list", "-f", "{{with .Replace}}{{.Dir}}{{end}}", "-m", "golang.org/x/tools")
+	cmd := Command(t, "%%GO_CMD%%", "list", "-f", "{{with .Replace}}{{.Dir}}{{end}}", "-m", "golang.org/x/tools")
 	out, err := cmd.Output()
 	if err != nil {
 		if ee, ok := err.(*exec.ExitError); ok && len(ee.Stderr) > 0 {
