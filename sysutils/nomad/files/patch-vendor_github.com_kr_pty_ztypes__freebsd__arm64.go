--- vendor/github.com/kr/pty/ztypes_freebsd_arm64.go.orig	2021-03-12 08:59:29 UTC
+++ vendor/github.com/kr/pty/ztypes_freebsd_arm64.go
@@ -0,0 +1,13 @@
+// Created by cgo -godefs - DO NOT EDIT
+// cgo -godefs types_freebsd.go
+
+package pty
+
+const (
+	_C_SPECNAMELEN = 0x3f
+)
+
+type fiodgnameArg struct {
+	Len       int32
+	Buf       *byte
+}
