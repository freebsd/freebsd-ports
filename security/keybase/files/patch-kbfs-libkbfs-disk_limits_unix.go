--- kbfs/libkbfs/disk_limits_unix.go.orig	2019-08-20 18:00:51 UTC
+++ kbfs/libkbfs/disk_limits_unix.go
@@ -28,13 +28,13 @@ func getDiskLimits(path string) (
 	}
 
 	// Bavail is the free block count for an unprivileged user.
-	availableBytes = stat.Bavail * uint64(stat.Bsize)
+	availableBytes = uint64(stat.Bavail) * uint64(stat.Bsize)
 	totalBytes = stat.Blocks * uint64(stat.Bsize)
 	// Some filesystems, like btrfs, don't keep track of inodes.
 	// (See https://github.com/keybase/client/issues/6206 .) Use
 	// the total inode count to detect that case.
 	if stat.Files > 0 {
-		availableFiles = stat.Ffree
+		availableFiles = uint64(stat.Ffree)
 		totalFiles = stat.Files
 	} else {
 		availableFiles = math.MaxInt64
