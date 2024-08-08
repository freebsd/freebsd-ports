--- internal/database/sqlite_noncgo.go.orig	1979-11-29 23:00:00 UTC
+++ internal/database/sqlite_noncgo.go
@@ -1,5 +1,5 @@
-//go:build linux || windows || darwin
-// +build linux windows darwin
+//go:build linux || windows || darwin || freebsd
+// +build linux windows darwin freebsd
 
 package database
 
