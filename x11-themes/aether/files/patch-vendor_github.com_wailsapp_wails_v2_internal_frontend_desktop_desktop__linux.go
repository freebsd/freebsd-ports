--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/desktop_linux.go.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/desktop_linux.go
@@ -1,5 +1,5 @@
-//go:build linux
-// +build linux
+//go:build linux || freebsd
+// +build linux freebsd
 
 package desktop
 
