--- vendor/github.com/nats-io/nats-server/v2/server/disk_avail.go.orig	2020-11-25 20:36:11 UTC
+++ vendor/github.com/nats-io/nats-server/v2/server/disk_avail.go
@@ -28,7 +28,7 @@ func diskAvailable(storeDir string) int64 {
 	var fs syscall.Statfs_t
 	if err := syscall.Statfs(storeDir, &fs); err == nil {
 		// Estimate 75% of available storage.
-		ba = int64(fs.Bavail * uint64(fs.Bsize) / 4 * 3)
+		ba = int64(uint64(fs.Bavail) * uint64(fs.Bsize) / 4 * 3)
 	} else {
 		// Used 1TB default as a guess if all else fails.
 		ba = JetStreamMaxStoreDefault
