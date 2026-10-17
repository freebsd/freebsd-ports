--- vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/request_linux.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/request_linux.go
@@ -1,10 +1,10 @@
-//go:build linux
-// +build linux
+//go:build linux || freebsd
+// +build linux freebsd
 
 package webview
 
 /*
-#cgo linux pkg-config: gtk+-3.0 gio-unix-2.0
+#cgo linux freebsd pkg-config: gtk+-3.0 gio-unix-2.0
 #cgo !webkit2_41 pkg-config: webkit2gtk-4.0
 #cgo webkit2_41 pkg-config: webkit2gtk-4.1
 
