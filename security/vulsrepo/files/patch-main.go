--- main.go.orig	2021-12-20 04:40:08 UTC
+++ main.go
@@ -134,8 +134,7 @@ func loadConfig() {
 }
 
 func loadConfig() {
-	fpath, _ := (os.Executable())
-	_, err := toml.DecodeFile(filepath.Dir(fpath)+"/vulsrepo-config.toml", &config)
+	_, err := toml.DecodeFile("%%PREFIX%%/etc/vulsrepo-config.toml", &config)
 	if err != nil {
 		_, err := toml.DecodeFile("./vulsrepo-config.toml", &config)
 		if err != nil {
