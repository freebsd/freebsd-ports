--- vendor/golang.org/x/telemetry/internal/configstore/download.go.orig	2025-05-08 09:35:28 UTC
+++ vendor/golang.org/x/telemetry/internal/configstore/download.go
@@ -36,7 +36,7 @@ func Download(version string, envOverlay []string) (*t
 	}
 	modVer := ModulePath + "@" + version
 	var stdout, stderr bytes.Buffer
-	cmd := exec.Command("go", "mod", "download", "-json", modVer)
+	cmd := exec.Command("%%GO_CMD%%", "mod", "download", "-json", modVer)
 	cmd.Env = append(os.Environ(), envOverlay...)
 	cmd.Stdout = &stdout
 	cmd.Stderr = &stderr
