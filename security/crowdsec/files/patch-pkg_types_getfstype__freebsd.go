--- pkg/types/getfstype_freebsd.go.orig	2024-04-24 21:25:32 UTC
+++ pkg/types/getfstype_freebsd.go
@@ -0,0 +1,25 @@
+//go:build freebsd
+
+package types
+
+import (
+    "fmt"
+    "syscall"
+)
+
+func GetFSType(path string) (string, error) {
+	var fsStat syscall.Statfs_t
+
+	if err := syscall.Statfs(path, &fsStat); err != nil {
+		return "", fmt.Errorf("failed to get filesystem type: %w", err)
+	}
+
+	bs := fsStat.Fstypename
+
+	b := make([]byte, len(bs))
+	for i, v := range bs {
+		b[i] = byte(v)
+	}
+
+	return string(b), nil
+}
