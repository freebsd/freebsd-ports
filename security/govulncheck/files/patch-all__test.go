--- all_test.go.orig	2025-05-08 09:17:55 UTC
+++ all_test.go
@@ -84,7 +84,7 @@ func rungo(t *testing.T, args ...string) {
 	t.Helper()
 	testenv.NeedsGoBuild(t)
 
-	cmd := exec.Command("go", args...)
+	cmd := exec.Command("%%GO_CMD%%", args...)
 	if output, err := cmd.CombinedOutput(); err != nil {
 		if ee := (*exec.ExitError)(nil); errors.As(err, &ee) && len(ee.Stderr) > 0 {
 			t.Fatalf("%v: %v\n%s", cmd, err, ee.Stderr)
