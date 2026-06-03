--- kbfs/libkbfs/disk_limits_unix.go.orig	2026-03-02 19:53:34 UTC
+++ kbfs/libkbfs/disk_limits_unix.go
@@ -31,14 +31,14 @@ func getDiskLimits(path string) (
 
 	// Bavail is the free block count for an unprivileged user.
 	// #nosec G115 -- Bsize is typically uint32 or int64 depending on platform, conversion to uint64 is safe
-	availableBytes = stat.Bavail * uint64(stat.Bsize)
+	availableBytes = uint64(stat.Bavail) * uint64(stat.Bsize)
 	// #nosec G115 -- Bsize is typically uint32 or int64 depending on platform, conversion to uint64 is safe
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
