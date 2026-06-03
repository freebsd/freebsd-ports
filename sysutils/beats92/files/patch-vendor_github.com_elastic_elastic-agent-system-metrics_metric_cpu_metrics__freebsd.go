--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go.orig	2026-03-16 23:13:36 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go
@@ -56,3 +56,7 @@ func parseCPULine(line string) (CPU, error) {
 
 	return cpuData, errors.Join(errs...)
 }
+
+func scanCPUInfoFile(scanner *bufio.Scanner) ([]CPUInfo, error) {
+	return cpuinfoScanner(scanner)
+}
