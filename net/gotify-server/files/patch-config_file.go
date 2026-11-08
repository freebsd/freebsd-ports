--- config/file.go.orig	2026-08-11 11:36:05 UTC
+++ config/file.go
@@ -46,7 +46,7 @@ func getFiles() []string {
 	if configHome := getConfigHome(); configHome != "" {
 		result = append(result, filepath.Join(configHome, "gotify/gotify-server.env"))
 	}
-	return append(result, "/etc/gotify/server.env")
+	return append(result, "/usr/local/etc/gotify-server/server.env")
 }
 
 func getConfigHome() string {
