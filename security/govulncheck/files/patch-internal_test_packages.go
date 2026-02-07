--- internal/test/packages.go.orig	2025-05-08 09:19:24 UTC
+++ internal/test/packages.go
@@ -13,7 +13,7 @@ func VerifyImports(t *testing.T, allowed ...string) {
 )
 
 func VerifyImports(t *testing.T, allowed ...string) {
-	if _, err := exec.LookPath("go"); err != nil {
+	if _, err := exec.LookPath("%%GO_CMD%%"); err != nil {
 		t.Skipf("skipping: %v", err)
 	}
 	cfg := &packages.Config{Mode: packages.NeedImports | packages.NeedDeps}
