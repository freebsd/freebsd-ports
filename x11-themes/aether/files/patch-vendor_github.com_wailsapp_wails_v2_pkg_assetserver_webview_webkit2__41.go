--- vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_41.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_41.go
@@ -1,4 +1,4 @@
-//go:build linux && webkit2_41
+//go:build (linux || freebsd) && webkit2_41
 
 package webview
 
