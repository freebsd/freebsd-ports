--- internal/scan/run.go.orig	2025-05-08 09:21:10 UTC
+++ internal/scan/run.go
@@ -87,7 +87,7 @@ func prepareConfig(ctx context.Context, cfg *config, c
 			}
 		}
 		if cfg.GoVersion == "" {
-			if out, err := exec.Command("go", "env", "GOVERSION").Output(); err == nil {
+			if out, err := exec.Command("%%GO_CMD%%", "env", "GOVERSION").Output(); err == nil {
 				cfg.GoVersion = strings.TrimSpace(string(out))
 			}
 		}
