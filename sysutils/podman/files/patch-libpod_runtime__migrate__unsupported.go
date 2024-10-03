--- libpod/runtime_migrate_unsupported.go.orig	2024-10-03 14:38:54 UTC
+++ libpod/runtime_migrate_unsupported.go
@@ -1,4 +1,4 @@
-//go:build !remote && !linux
+//go:build !remote && !linux && !freebsd
 
 package libpod
 
