--- ml/path.go.orig	2025-11-29 01:38:34.298472000 -0800
+++ ml/path.go	2025-11-29 01:39:10.084873000 -0800
@@ -27,7 +27,7 @@
 	switch runtime.GOOS {
 	case "windows":
 		libPath = filepath.Join(filepath.Dir(exe), "lib", "ollama")
-	case "linux":
+	case "linux", "freebsd":
 		libPath = filepath.Join(filepath.Dir(exe), "..", "lib", "ollama")
 	case "darwin":
 		libPath = filepath.Dir(exe)
