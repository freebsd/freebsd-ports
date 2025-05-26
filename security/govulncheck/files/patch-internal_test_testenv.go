--- internal/test/testenv.go.orig	2025-05-08 09:18:33 UTC
+++ internal/test/testenv.go
@@ -14,7 +14,7 @@ func NeedsGoEnv(t testing.TB) {
 func NeedsGoEnv(t testing.TB) {
 	t.Helper()
 
-	if _, err := exec.LookPath("go"); err != nil {
+	if _, err := exec.LookPath("%%GO_CMD%%"); err != nil {
 		t.Skip("skipping test: can't run go env")
 	}
 }
