--- vendor/github.com/DataDog/gopsutil/disk/disk_freebsd.go.orig	2020-11-16 16:21:58 UTC
+++ vendor/github.com/DataDog/gopsutil/disk/disk_freebsd.go
@@ -77,9 +77,9 @@ func Partitions(all bool) ([]PartitionStat, error) {
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
@@ -172,5 +172,5 @@ func parseDevstat(buf []byte) (Devstat, error) {
 }
 
 func getFsType(stat syscall.Statfs_t) string {
-	return common.IntToString(stat.Fstypename[:])
+	return common.ByteToString(stat.Fstypename[:])
 }
