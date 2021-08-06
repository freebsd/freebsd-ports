--- drivers/docker/driver_freebsd_test.go.orig	2021-08-06 23:51:59 UTC
+++ drivers/docker/driver_freebsd_test.go
@@ -0,0 +1,26 @@
+package docker
+
+import (
+	"fmt"
+	"os"
+	"testing"
+	"time"
+)
+
+// TestMain is a hacky test entrypoint to set temp directory to a path that can
+// be mounted into Docker containers on macOS without needing dev performing
+// special setup.
+//
+// macOS sets tempdir as `/var`, which Docker does not allowlist as a path that
+// can be bind-mounted.
+func TestMain(m *testing.M) {
+	tmpdir := fmt.Sprintf("/tmp/nomad-docker-tests-%d", time.Now().Unix())
+
+	defer os.Setenv("TMPDIR", os.Getenv("TMPDIR"))
+	os.Setenv("TMPDIR", tmpdir)
+
+	os.MkdirAll(tmpdir, 0700)
+	defer os.RemoveAll(tmpdir)
+
+	os.Exit(m.Run())
+}
