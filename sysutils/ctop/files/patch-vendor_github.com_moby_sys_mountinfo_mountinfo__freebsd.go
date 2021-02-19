--- vendor/github.com/moby/sys/mountinfo/mountinfo_freebsd.go.orig	2021-02-19 17:23:37 UTC
+++ vendor/github.com/moby/sys/mountinfo/mountinfo_freebsd.go
@@ -9,6 +9,7 @@ import "C"
 
 import (
 	"fmt"
+	"io"
 	"reflect"
 	"unsafe"
 )
@@ -50,4 +51,8 @@ func parseMountTable(filter FilterFunc) ([]*Info, erro
 		}
 	}
 	return out, nil
+}
+
+func parseInfoFile(_ io.Reader, f FilterFunc) ([]*Info, error) {
+	return parseMountTable(f)
 }
