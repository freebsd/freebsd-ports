--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go.orig	2022-11-25 21:56:24 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/cpu/metrics_freebsd.go
@@ -57,3 +57,7 @@ func parseCPULine(line string) (CPU, error) {
 
 	return cpuData, errs.Err()
 }
+
+func scanCPUInfoFile(scanner *bufio.Scanner) ([]CPUInfo, error) {
+	return cpuinfoScanner(scanner)
+}
