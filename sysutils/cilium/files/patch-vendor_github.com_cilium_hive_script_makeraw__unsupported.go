--- vendor/github.com/cilium/hive/script/makeraw_unsupported.go.orig	2024-11-30 05:14:56 UTC
+++ vendor/github.com/cilium/hive/script/makeraw_unsupported.go
@@ -11,6 +11,6 @@ import (
 	"runtime"
 )
 
-func MakeRaw(fd int) (restore func(), err error) {
+func MakeRawUnsupported(fd int) (restore func(), err error) {
 	return func() {}, fmt.Errorf("MakeRaw: not supported on %s", runtime.GOOS)
 }
