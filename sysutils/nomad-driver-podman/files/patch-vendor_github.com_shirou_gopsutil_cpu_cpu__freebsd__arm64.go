--- vendor/github.com/shirou/gopsutil/cpu/cpu_freebsd_arm64.go.orig	2021-05-28 13:42:23 UTC
+++ vendor/github.com/shirou/gopsutil/cpu/cpu_freebsd_arm64.go
@@ -0,0 +1,9 @@
+package cpu
+
+type cpuTimes struct {
+	User uint64
+	Nice uint64
+	Sys  uint64
+	Intr uint64
+	Idle uint64
+}
