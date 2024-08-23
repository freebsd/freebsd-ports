--- vendor/github.com/containers/storage/pkg/fileutils/exists_unix.go.orig	2024-08-23 10:19:17 UTC
+++ vendor/github.com/containers/storage/pkg/fileutils/exists_unix.go
@@ -1,5 +1,5 @@
-//go:build !windows
-// +build !windows
+//go:build !windows && !freebsd
+// +build !windows,!freebsd
 
 package fileutils
 
