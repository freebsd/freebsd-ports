--- internal/testenv/testenv.go.orig	2025-05-08 09:21:55 UTC
+++ internal/testenv/testenv.go
@@ -100,7 +100,7 @@ func NeedsGoBuild(t testing.TB) {
 		if err := os.WriteFile(mainGo, []byte("package main\nfunc main() {}\n"), 0644); err != nil {
 			t.Fatal(err)
 		}
-		cmd := exec.Command("go", "build", "-o", os.DevNull, mainGo)
+		cmd := exec.Command("%%GO_CMD%%", "build", "-o", os.DevNull, mainGo)
 		cmd.Dir = dir
 		if err := cmd.Run(); err != nil {
 			goBuildErr = fmt.Errorf("%v: %v", cmd, err)
