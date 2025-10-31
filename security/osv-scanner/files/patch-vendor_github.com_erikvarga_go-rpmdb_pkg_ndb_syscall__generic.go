--- vendor/github.com/erikvarga/go-rpmdb/pkg/ndb/syscall_generic.go.orig	2025-10-31 03:51:39 UTC
+++ vendor/github.com/erikvarga/go-rpmdb/pkg/ndb/syscall_generic.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin
+//go:build linux || darwin || freebsd
 
 package ndb
 
