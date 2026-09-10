--- x/mlxrunner/mlx/dynamic.go.orig	1979-11-30 08:00:00 UTC
+++ x/mlxrunner/mlx/dynamic.go
@@ -98,7 +98,7 @@ func libOllamaRoots() []string {
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
 			roots = append(roots, filepath.Join(exeDir, "..", "lib", "ollama"))
 			roots = append(roots, exeDir) // app bundle: Contents/Resources/
-		case "linux":
+		case "linux", "freebsd":
 			roots = append(roots, filepath.Join(exeDir, "..", "lib", "ollama"))
 		case "windows":
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
@@ -175,7 +175,7 @@ func prependLibraryPath(dir string) {
 	switch runtime.GOOS {
 	case "darwin":
 		envVar = "DYLD_LIBRARY_PATH"
-	case "linux":
+	case "linux", "freebsd":
 		envVar = "LD_LIBRARY_PATH"
 	default:
 		return
@@ -189,7 +189,7 @@ func init() {
 
 func init() {
 	switch runtime.GOOS {
-	case "darwin", "linux", "windows":
+	case "darwin", "linux", "freebsd", "windows":
 	default:
 		return
 	}
