--- vendor/github.com/wailsapp/wails/v2/internal/app/app_preflight_unix.go.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/app/app_preflight_unix.go
@@ -1,4 +1,4 @@
-//go:build (linux || darwin) && !bindings
+//go:build (linux || darwin || freebsd) && !bindings
 
 package app
 
