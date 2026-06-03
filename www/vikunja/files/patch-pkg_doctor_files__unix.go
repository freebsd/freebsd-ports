--- pkg/doctor/files_unix.go.orig	2026-03-23 20:49:15 UTC
+++ pkg/doctor/files_unix.go
@@ -40,7 +40,7 @@ func checkDiskSpace(path string) CheckResult {
 	}
 
 	// Available space in bytes
-	availableBytes := stat.Bavail * uint64(stat.Bsize)
+	availableBytes := uint64(stat.Bavail) * uint64(stat.Bsize)
 	availableGB := float64(availableBytes) / (1024 * 1024 * 1024)
 
 	return CheckResult{
