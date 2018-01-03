--- components/cli/vendor/github.com/tonistiigi/fsutil/diskwriter_freebsd.go.orig	2018-01-03 19:54:52 UTC
+++ components/cli/vendor/github.com/tonistiigi/fsutil/diskwriter_freebsd.go
@@ -0,0 +1,20 @@
+// +build freebsd
+
+package fsutil
+
+import (
+	"github.com/pkg/errors"
+	"golang.org/x/sys/unix"
+)
+
+func chtimes(path string, un int64) error {
+	var utimes [2]unix.Timespec
+	utimes[0] = unix.NsecToTimespec(un)
+	utimes[1] = utimes[0]
+
+	if err := unix.UtimesNanoAt(unix.AT_FDCWD, path, utimes[0:], unix.AT_SYMLINK_NOFOLLOW); err != nil {
+		return errors.Wrap(err, "failed call to UtimesNanoAt")
+	}
+
+	return nil
+}
