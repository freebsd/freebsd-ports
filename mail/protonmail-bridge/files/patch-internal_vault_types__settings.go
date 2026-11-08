--- internal/vault/types_settings.go.orig	2026-07-26 09:46:27 UTC
+++ internal/vault/types_settings.go
@@ -91,7 +91,7 @@ func newDefaultSettings(gluonDir string) Settings {
 		ProxyAllowed:      false,
 		ShowAllMail:       true,
 		Autostart:         true,
-		AutoUpdate:        true,
+		AutoUpdate:        false,
 		TelemetryDisabled: false,
 
 		LastVersion: "0.0.0",
