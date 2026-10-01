--- vendor/github.com/wailsapp/wails/v2/internal/app/app_default_unix.go.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/app/app_default_unix.go
@@ -1,4 +1,4 @@
-//go:build !dev && !production && !bindings && (linux || darwin)
+//go:build !dev && !production && !bindings && (linux || darwin || freebsd)
 
 package app
 
