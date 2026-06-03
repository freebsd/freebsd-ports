--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_procfs_common.go.orig	2026-03-16 23:17:26 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_procfs_common.go
@@ -32,7 +32,7 @@ func Get(m *Monitor) (CPUMetrics, error) {
 func Get(m *Monitor) (CPUMetrics, error) {
 	procfs := m.Hostfs
 
-	path := procfs.ResolveHostFS("/proc/stat")
+	path := procfs.ResolveHostFS("/compat/linux/proc/stat")
 	fd, err := os.Open(path)
 	defer func() {
 		_ = fd.Close()
@@ -46,7 +46,7 @@ func Get(m *Monitor) (CPUMetrics, error) {
 		return CPUMetrics{}, fmt.Errorf("scanning stat file: %w", err)
 	}
 
-	cpuInfoPath := procfs.ResolveHostFS("/proc/cpuinfo")
+	cpuInfoPath := procfs.ResolveHostFS("/compat/linux/proc/cpuinfo")
 	cpuInfoFd, err := os.Open(cpuInfoPath)
 	if err != nil {
 		return CPUMetrics{}, fmt.Errorf("opening '%s': %w", cpuInfoPath, err)
