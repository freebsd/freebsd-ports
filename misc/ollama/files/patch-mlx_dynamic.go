--- mlx/dynamic.go.orig	1979-11-30 08:00:00 UTC
+++ mlx/dynamic.go
@@ -109,7 +109,7 @@ func libOllamaRoots() []string {
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
 			roots = append(roots, filepath.Join(exeDir, "..", "lib", "ollama"))
 			roots = append(roots, exeDir) // app bundle: Contents/Resources/
-		case "linux":
+		case "linux", "freebsd":
 			roots = append(roots, filepath.Join(exeDir, "..", "lib", "ollama"))
 		case "windows":
 			roots = append(roots, filepath.Join(exeDir, "lib", "ollama"))
@@ -184,7 +184,7 @@ func libraryPathEnvVar() string {
 		return "PATH"
 	case "darwin":
 		return "DYLD_LIBRARY_PATH"
-	case "linux":
+	case "linux", "freebsd":
 		return "LD_LIBRARY_PATH"
 	default:
 		return ""
@@ -276,7 +276,7 @@ func init() {
 
 func init() {
 	switch runtime.GOOS {
-	case "darwin", "linux", "windows":
+	case "darwin", "linux", "freebsd", "windows":
 	default:
 		return
 	}
