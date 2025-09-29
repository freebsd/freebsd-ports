--- diagnostic/network/collector_unix.go.orig	2024-01-01 00:00:00 UTC
+++ diagnostic/network/collector_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux
+//go:build darwin || linux || freebsd
 
 package diagnostic
 
