--- vendor/github.com/wailsapp/wails/v2/pkg/runtime/signal_other.go.orig	2026-09-29 13:40:04 UTC
+++ vendor/github.com/wailsapp/wails/v2/pkg/runtime/signal_other.go
@@ -1,4 +1,4 @@
-//go:build !linux
+//go:build !linux && !freebsd
 
 package runtime
 
