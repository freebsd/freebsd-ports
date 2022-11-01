--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_procfs_common.go.orig	2022-11-25 21:55:11 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_procfs_common.go
@@ -32,7 +32,7 @@ import (
 
 // Get returns a metrics object for CPU data
 func Get(procfs resolve.Resolver) (CPUMetrics, error) {
-	path := procfs.ResolveHostFS("/proc/stat")
+	path := procfs.ResolveHostFS("/compat/linux/proc/stat")
 	fd, err := os.Open(path)
 	defer func() {
 		_ = fd.Close()
@@ -46,7 +46,7 @@ func Get(procfs resolve.Resolver) (CPUMetrics, error) 
 		return CPUMetrics{}, fmt.Errorf("scanning stat file: %w", err)
 	}
 
-	cpuInfoPath := procfs.ResolveHostFS("/proc/cpuinfo")
+	cpuInfoPath := procfs.ResolveHostFS("/compat/linux/proc/cpuinfo")
 	cpuInfoFd, err := os.Open(cpuInfoPath)
 	if err != nil {
 		return CPUMetrics{}, fmt.Errorf("opening '%s': %w", cpuInfoPath, err)
