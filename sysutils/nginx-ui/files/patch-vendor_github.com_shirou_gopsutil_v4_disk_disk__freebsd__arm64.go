--- vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd_arm64.go.orig	2025-08-28 06:16:23 UTC
+++ vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd_arm64.go
@@ -52,7 +52,7 @@ type devstat struct {
 	Flags         uint32
 	Device_type   uint32
 	Priority      uint32
-	Id            *byte
+	Id            [sizeofPtr]byte
 	Sequence1     uint32
 	Pad_cgo_0     [4]byte
 }
