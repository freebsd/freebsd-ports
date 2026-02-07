--- vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker_freebsd_arm64.go.orig	2025-10-25 07:48:01 UTC
+++ vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker_freebsd_arm64.go
@@ -0,0 +1,10 @@
+//go:build freebsd && arm64
+// +build freebsd,arm64
+
+package chunker
+
+/*
+#cgo CFLAGS: -I/usr/local/include
+#cgo LDFLAGS: -L/usr/local/lib -lparser_c_bindings
+*/
+import "C"
