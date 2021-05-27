--- /dev/null	2021-05-26 18:56:22.470788000 -0700
+++ drivers/docker/driver_freebsd_test.go	2021-05-26 18:54:25.182401000 -0700
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
