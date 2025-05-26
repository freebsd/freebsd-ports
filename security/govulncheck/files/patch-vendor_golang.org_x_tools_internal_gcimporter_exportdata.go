--- vendor/golang.org/x/tools/internal/gcimporter/exportdata.go.orig	2025-05-08 09:32:45 UTC
+++ vendor/golang.org/x/tools/internal/gcimporter/exportdata.go
@@ -392,7 +392,7 @@ func lookupGorootExport(pkgDir string) (string, error)
 		)
 		f, _ = exportMap.LoadOrStore(pkgDir, func() (string, error) {
 			listOnce.Do(func() {
-				cmd := exec.Command(filepath.Join(build.Default.GOROOT, "bin", "go"), "list", "-export", "-f", "{{.Export}}", pkgDir)
+				cmd := exec.Command(filepath.Join(build.Default.GOROOT, "bin", "%%GO_CMD%%"), "list", "-export", "-f", "{{.Export}}", pkgDir)
 				cmd.Dir = build.Default.GOROOT
 				cmd.Env = append(os.Environ(), "PWD="+cmd.Dir, "GOROOT="+build.Default.GOROOT)
 				var output []byte
