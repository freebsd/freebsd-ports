--- config/config.go.orig	2024-09-23 15:32:25 UTC
+++ config/config.go
@@ -6,12 +6,9 @@ func Path(filename string) (string, error) {
 )
 
 func Path(filename string) (string, error) {
-	configHome, err := os.UserConfigDir()
-	if err != nil {
-		return "", err
-	}
+	configHome := "/var/db/hydroxide"
 
-	p := filepath.Join(configHome, "hydroxide", filename)
+	p := filepath.Join(configHome, filename)
 
 	dirname, _ := filepath.Split(p)
 	if err := os.MkdirAll(dirname, 0700); err != nil {
