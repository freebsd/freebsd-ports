--- pkg/fsutil/getfstype_freebsd.go.orig	2025-12-05 08:44:44 UTC
+++ pkg/fsutil/getfstype_freebsd.go
@@ -1,6 +1,6 @@
 //go:build freebsd
 
-package types
+package fsutil
 
 import (
     "fmt"
