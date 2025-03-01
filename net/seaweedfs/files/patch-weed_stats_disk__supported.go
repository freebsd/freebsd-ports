--- weed/stats/disk_supported.go.orig	1979-11-29 21:00:00 UTC
+++ weed/stats/disk_supported.go
@@ -20,7 +20,7 @@ func fillInDiskStatus(disk *volume_server_pb.DiskStatu
 	// fs.Bfree: Number of free blocks
 	// fs.Bavail: Number of free blocks for unprivileged users
 	// disk.Free = fs.Bfree * uint64(fs.Bsize)
-	disk.Free = fs.Bavail * uint64(fs.Bsize)
+	disk.Free = uint64(fs.Bavail) * uint64(fs.Bsize)
 	disk.Used = disk.All - disk.Free
 	disk.PercentFree = float32((float64(disk.Free) / float64(disk.All)) * 100)
 	disk.PercentUsed = float32((float64(disk.Used) / float64(disk.All)) * 100)
