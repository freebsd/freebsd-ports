--- config/config.go.orig	1979-11-29 23:00:00 UTC
+++ config/config.go
@@ -61,7 +61,7 @@ func configFiles() []string {
 	if mode.Get() == mode.TestDev {
 		return []string{"config.yml"}
 	}
-	return []string{"config.yml", "/etc/gotify/config.yml"}
+	return []string{"config.yml", "/usr/local/etc/gotify-server/config.yml"}
 }
 
 // Get returns the configuration extracted from env variables or config file.
