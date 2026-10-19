--- vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_36.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_36.go
@@ -1,9 +1,9 @@
-//go:build linux && webkit2_36
+//go:build (linux || freebsd) && webkit2_36
 
 package webview
 
 /*
-#cgo linux pkg-config: webkit2gtk-4.0
+#cgo linux freebsd pkg-config: webkit2gtk-4.0
 
 #include "webkit2/webkit2.h"
 */
