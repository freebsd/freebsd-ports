--- pkg/systemmetrics/metric/cpu/metrics_freebsd.go.orig	2026-09-30 21:45:44 UTC
+++ pkg/systemmetrics/metric/cpu/metrics_freebsd.go
@@ -56,3 +56,7 @@ func parseCPULine(line string) (CPU, error) {
 
 	return cpuData, errors.Join(errs...)
 }
+
+func scanCPUInfoFile(scanner *bufio.Scanner) ([]CPUInfo, error) {
+	return cpuinfoScanner(scanner)
+}
