--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/clipboard.go.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/clipboard.go
@@ -1,10 +1,10 @@
-//go:build linux
-// +build linux
+//go:build linux || freebsd
+// +build linux freebsd
 
 package linux
 
 /*
-#cgo linux pkg-config: gtk+-3.0
+#cgo linux freebsd pkg-config: gtk+-3.0
 #cgo !webkit2_41 pkg-config: webkit2gtk-4.0
 #cgo webkit2_41 pkg-config: webkit2gtk-4.1
 
