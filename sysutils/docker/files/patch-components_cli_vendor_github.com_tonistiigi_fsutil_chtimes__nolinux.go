--- components/cli/vendor/github.com/tonistiigi/fsutil/chtimes_nolinux.go.orig	2018-08-03 15:31:57 UTC
+++ components/cli/vendor/github.com/tonistiigi/fsutil/chtimes_nolinux.go
@@ -1,4 +1,4 @@
-// +build !linux
+// +build !linux,!freebsd
 
 package fsutil
 
