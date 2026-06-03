--- x/mlxrunner/mlx/dynamic.go.orig	2026-04-09 01:42:19 UTC
+++ x/mlxrunner/mlx/dynamic.go
@@ -83,7 +83,7 @@ func libOllamaRoots() []string {
 		case "darwin":
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
 			roots = append(roots, exeDir) // app bundle: Contents/Resources/
-		case "linux":
+		case "linux", "freebsd":
 			roots = append(roots, filepath.Join(exeDir, "..", "lib", "ollama"))
 		case "windows":
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
@@ -143,7 +143,7 @@ func prependLibraryPath(dir string) {
 	switch runtime.GOOS {
 	case "darwin":
 		envVar = "DYLD_LIBRARY_PATH"
-	case "linux":
+	case "linux", "freebsd":
 		envVar = "LD_LIBRARY_PATH"
 	default:
 		return
@@ -157,7 +157,7 @@ func init() {
 
 func init() {
 	switch runtime.GOOS {
-	case "darwin", "linux", "windows":
+	case "darwin", "linux", "freebsd", "windows":
 	default:
 		return
 	}
