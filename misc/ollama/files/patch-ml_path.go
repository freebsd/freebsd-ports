--- ml/path.go.orig	1979-11-30 08:00:00 UTC
+++ ml/path.go
@@ -27,7 +27,7 @@ var LibOllamaPath string = func() string {
 	switch runtime.GOOS {
 	case "windows":
 		libPath = filepath.Join(filepath.Dir(exe), "lib", "ollama")
-	case "linux":
+	case "linux", "freebsd":
 		libPath = filepath.Join(filepath.Dir(exe), "..", "lib", "ollama")
 	case "darwin":
 		libPath = filepath.Dir(exe)
