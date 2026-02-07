--- command/agent/log_file_bsd_386.go.orig	2021-12-15 03:59:45 UTC
+++ command/agent/log_file_bsd_386.go
@@ -0,0 +1,17 @@
+//go:build 386 && (darwin || freebsd || netbsd || openbsd)
+// +build 386
+// +build darwin freebsd netbsd openbsd
+
+package agent
+
+import (
+	"os"
+	"syscall"
+	"time"
+)
+
+func (l *logFile) createTime(stat os.FileInfo) time.Time {
+	stat_t := stat.Sys().(*syscall.Stat_t)
+	createTime := stat_t.Ctimespec
+	return time.Unix(int64(createTime.Sec), int64(createTime.Nsec))
+}
