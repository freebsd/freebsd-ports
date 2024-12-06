--- vendor/github.com/containers/storage/pkg/fileutils/exists_unix.go.orig	2024-12-06 15:50:49 UTC
+++ vendor/github.com/containers/storage/pkg/fileutils/exists_unix.go
@@ -1,5 +1,4 @@
-//go:build !windows
-// +build !windows
+//go:build !windows && !freebsd
 
 package fileutils
 
