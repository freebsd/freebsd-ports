--- src/github.com/concourse/go-archive/tarfs/mknod.go.orig	2019-03-04 10:29:20 UTC
+++ src/github.com/concourse/go-archive/tarfs/mknod.go
@@ -1,4 +1,4 @@
-// +build !windows
+// +build !windows,!freebsd
 
 package tarfs
 
