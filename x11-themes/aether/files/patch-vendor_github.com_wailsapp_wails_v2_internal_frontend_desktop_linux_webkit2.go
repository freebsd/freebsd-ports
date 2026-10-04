--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/webkit2.go.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/webkit2.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux || freebsd
 
 package linux
 
