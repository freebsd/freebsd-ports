--- vendor/github.com/shirou/gopsutil/disk/disk_freebsd.go.orig	2020-05-14 21:25:30 UTC
+++ vendor/github.com/shirou/gopsutil/disk/disk_freebsd.go
@@ -84,9 +84,9 @@ func PartitionsWithContext(ctx context.Context, all bo
 		}
 
 		d := PartitionStat{
-			Device:     common.IntToString(stat.Mntfromname[:]),
-			Mountpoint: common.IntToString(stat.Mntonname[:]),
-			Fstype:     common.IntToString(stat.Fstypename[:]),
+			Device:     common.ByteToString(stat.Mntfromname[:]),
+			Mountpoint: common.ByteToString(stat.Mntonname[:]),
+			Fstype:     common.ByteToString(stat.Fstypename[:]),
 			Opts:       opts,
 		}
 		if all == false {
@@ -170,5 +170,5 @@ func parseDevstat(buf []byte) (Devstat, error) {
 }
 
 func getFsType(stat unix.Statfs_t) string {
-	return common.IntToString(stat.Fstypename[:])
+	return common.ByteToString(stat.Fstypename[:])
 }
