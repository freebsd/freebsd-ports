--- vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd_amd64.go.orig	2025-08-28 06:15:24 UTC
+++ vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd_amd64.go
@@ -52,7 +52,7 @@ type devstat struct {
 	Device_type   uint32
 	Priority      uint32
 	Pad_cgo_1     [4]byte
-	ID            *byte
+	ID            [sizeofPtr]byte
 	Sequence1     uint32
 	Pad_cgo_2     [4]byte
 }
