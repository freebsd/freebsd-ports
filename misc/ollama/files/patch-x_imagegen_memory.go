--- x/imagegen/memory.go.orig	2026-03-12 23:02:15 UTC
+++ x/imagegen/memory.go
@@ -31,7 +31,7 @@ func CheckPlatformSupport() error {
 			return fmt.Errorf("image generation on macOS requires Apple Silicon (arm64), got %s", runtime.GOARCH)
 		}
 		return nil
-	case "linux", "windows":
+	case "linux", "windows", "freebsd":
 		// Linux/Windows: CUDA support (requires mlx or cuda build)
 		// The actual backend availability is checked at runtime
 		return nil
