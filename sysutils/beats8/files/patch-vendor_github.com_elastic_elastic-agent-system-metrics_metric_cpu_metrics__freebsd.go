--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go.orig	2025-09-19 18:38:09 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go
@@ -56,3 +56,7 @@ func parseCPULine(line string) (CPU, error) {
 
 	return cpuData, errors.Join(errs...)
 }
+
+func scanCPUInfoFile(scanner *bufio.Scanner) ([]CPUInfo, error) {
+	return cpuinfoScanner(scanner)
+}
