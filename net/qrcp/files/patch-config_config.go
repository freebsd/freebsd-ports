--- config/config.go.orig	2023-04-09 08:36:02 UTC
+++ config/config.go
@@ -38,7 +38,7 @@ func New(app application.App) Config {
 
 	_, err = os.Stat(v.ConfigFileUsed())
 	if os.IsNotExist(err) {
-		if err := os.MkdirAll(filepath.Dir(v.ConfigFileUsed()), os.ModeDir); err != nil {
+		if err := os.MkdirAll(filepath.Dir(v.ConfigFileUsed()), os.ModeDir | os.ModePerm); err != nil {
 			panic(err)
 		}
 		file, err := os.Create(v.ConfigFileUsed())
