--- vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker_freebsd_amd64.go.orig	2025-10-25 07:47:52 UTC
+++ vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker_freebsd_amd64.go
@@ -0,0 +1,10 @@
+//go:build freebsd && amd64
+// +build freebsd,amd64
+
+package chunker
+
+/*
+#cgo CFLAGS: -I/usr/local/include
+#cgo LDFLAGS: -L/usr/local/lib -lparser_c_bindings
+*/
+import "C"
