--- config/config.go.orig	2024-10-11 14:37:05 UTC
+++ config/config.go
@@ -60,7 +60,7 @@ func configFiles() []string {
 	if mode.Get() == mode.TestDev {
 		return []string{"config.yml"}
 	}
-	return []string{"config.yml", "/etc/gotify/config.yml"}
+	return []string{"config.yml", "/usr/local/etc/gotify-server/config.yml"}
 }
 
 // Get returns the configuration extracted from env variables or config file.
