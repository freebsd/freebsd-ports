--- internal/platform/protocol.go.orig	2026-09-20 08:33:19 UTC
+++ internal/platform/protocol.go
@@ -15,7 +15,7 @@ func EnsureURLHandler(ctx context.Context) error {
 
 // EnsureURLHandler makes Aether the current user's handler for aether:// URLs.
 func EnsureURLHandler(ctx context.Context) error {
-	if runtime.GOOS != "linux" {
+	if runtime.GOOS != "linux" && runtime.GOOS != "freebsd" {
 		return nil
 	}
 	if !CommandExists("xdg-mime") {
