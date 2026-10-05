--- vendor/github.com/wailsapp/wails/v2/pkg/runtime/signal_linux.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/runtime/signal_linux.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux || freebsd
 
 package runtime
 
