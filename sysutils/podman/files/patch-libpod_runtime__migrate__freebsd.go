--- libpod/runtime_migrate_freebsd.go.orig	2024-10-03 14:39:32 UTC
+++ libpod/runtime_migrate_freebsd.go
@@ -0,0 +1,15 @@
+//go:build !remote
+
+package libpod
+
+import (
+	"errors"
+)
+
+func (r *Runtime) stopPauseProcess() error {
+	return nil
+}
+
+func (r *Runtime) Migrate(newRuntime string) error {
+	return errors.New("not implemented (*Runtime) migrate")
+}
