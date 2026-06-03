--- vendor/golang.org/x/telemetry/internal/configstore/download.go.orig	2026-04-14 11:02:21 UTC
+++ vendor/golang.org/x/telemetry/internal/configstore/download.go
@@ -51,7 +51,7 @@ func Download(version string, envOverlay []string) (*t
 	}
 	modVer := ModulePath + "@" + version
 	var stdout, stderr bytes.Buffer
-	cmd := exec.Command("go", "mod", "download", "-json", modVer)
+	cmd := exec.Command("%%GO_CMD%%", "mod", "download", "-json", modVer)
 	needNoConsole(cmd)
 	cmd.Env = append(os.Environ(), envOverlay...)
 	cmd.Stdout = &stdout
