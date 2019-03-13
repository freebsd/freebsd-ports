--- src/github.com/concourse/go-archive/tarfs/mknod_freebsd.go.orig	2019-03-13 13:08:01 UTC
+++ src/github.com/concourse/go-archive/tarfs/mknod_freebsd.go
@@ -0,0 +1,28 @@
+// +build freebsd
+
+package tarfs
+
+import (
+	"archive/tar"
+	"syscall"
+
+	"golang.org/x/sys/unix"
+)
+
+func mknodEntry(hdr *tar.Header, path string) error {
+	mode := uint32(hdr.Mode & 07777)
+	switch hdr.Typeflag {
+	case tar.TypeBlock:
+		mode |= unix.S_IFBLK
+	case tar.TypeChar:
+		mode |= unix.S_IFCHR
+	case tar.TypeFifo:
+		mode |= unix.S_IFIFO
+	}
+
+	return syscall.Mknod(path, mode, uint64(mkdev(hdr.Devmajor, hdr.Devminor)))
+}
+
+func mkdev(major, minor int64) uint32 {
+	return uint32(((minor & 0xfff00) << 12) | ((major & 0xfff) << 8) | (minor & 0xff))
+}
