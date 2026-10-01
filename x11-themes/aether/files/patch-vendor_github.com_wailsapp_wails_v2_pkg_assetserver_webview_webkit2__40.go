--- vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_40.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/assetserver/webview/webkit2_40.go
@@ -1,4 +1,4 @@
-//go:build linux && webkit2_40
+//go:build (linux || freebsd) && webkit2_40
 
 package webview
 
