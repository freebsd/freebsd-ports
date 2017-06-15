--- agent/fileutil/fileutil_unix.go.orig	2016-07-06 21:51:35 UTC
+++ agent/fileutil/fileutil_unix.go
@@ -85,9 +85,9 @@ func GetDiskSpaceInfo() (diskSpaceInfo D
 
 	// return DiskSpaceInfo with calculated bytes
 	return DiskSpaceInfo{
-		AvailBytes: (int64)(stat.Bavail * bSize), // available space = # of available blocks * block size
-		FreeBytes:  (int64)(stat.Bfree * bSize),  // free space = # of free blocks * block size
-		TotalBytes: (int64)(stat.Blocks * bSize), // total space = # of total blocks * block size
+		AvailBytes: (int64)((uint64)(stat.Bavail) * bSize), // available space = # of available blocks * block size
+		FreeBytes:  (int64)(stat.Bfree * bSize),            // free space = # of free blocks * block size
+		TotalBytes: (int64)(stat.Blocks * bSize),           // total space = # of total blocks * block size
 	}, nil
 }
 
