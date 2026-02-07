--- vendor/golang.org/x/telemetry/internal/telemetry/dir.go.orig	2025-05-08 09:35:02 UTC
+++ vendor/golang.org/x/telemetry/internal/telemetry/dir.go
@@ -52,7 +52,7 @@ func init() {
 	if err != nil {
 		return
 	}
-	Default = NewDir(filepath.Join(cfgDir, "go", "telemetry"))
+	Default = NewDir(filepath.Join(cfgDir, "%%GO_CMD%%", "telemetry"))
 }
 
 func (d Dir) Dir() string {
