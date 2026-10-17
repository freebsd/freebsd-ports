--- vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_40+.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_40+.go
@@ -1,9 +1,9 @@
-//go:build linux && (webkit2_40 || webkit2_41)
+//go:build (linux || freebsd) && (webkit2_40 || webkit2_41)
 
 package webview
 
 /*
-#cgo linux pkg-config: gtk+-3.0 gio-unix-2.0
+#cgo linux freebsd pkg-config: gtk+-3.0 gio-unix-2.0
 #cgo !webkit2_41 pkg-config: webkit2gtk-4.0
 #cgo webkit2_41 pkg-config: webkit2gtk-4.1
 
