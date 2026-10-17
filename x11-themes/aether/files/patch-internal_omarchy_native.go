--- internal/omarchy/native.go.orig	2026-09-20 08:33:19 UTC
+++ internal/omarchy/native.go
@@ -53,7 +53,7 @@ func IsInstalled() bool {
 
 // IsInstalled reports whether the public Omarchy command is available.
 func IsInstalled() bool {
-	return runtime.GOOS == "linux" && platform.CommandExists("omarchy")
+	return (runtime.GOOS == "linux" || runtime.GOOS == "freebsd") && platform.CommandExists("omarchy")
 }
 
 // DetectCapabilities returns the native paths and active theme for Omarchy.
