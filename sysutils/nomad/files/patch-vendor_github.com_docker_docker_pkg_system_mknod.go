--- vendor/github.com/docker/docker/pkg/system/mknod.go	2023-02-03 20:50:38.642086000 -0800
+++ vendor/github.com/docker/docker/pkg/system/mknod.go.orig	2023-02-03 20:50:27.280880000 -0800
@@ -13,5 +13,5 @@
 // They are, from low to high: the lower 8 bits of the minor, then 12 bits of the major,
 // then the top 12 bits of the minor.
 func Mkdev(major int64, minor int64) uint32 {
-	return uint32(unix.Mkdev(uint32(major), uint32(minor)))
+	return uint32(unix.Mkdev(uint32(major), uint32(minor)))
 }
