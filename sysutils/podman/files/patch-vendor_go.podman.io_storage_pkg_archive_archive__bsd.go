Fix loss of setuid/setgid/sticky bits during BSD untar.

Directly casting Go's os.FileMode to uint32 in handleLChmod silently
dropped setuid/setgid/sticky bits on BSD systems, since they are
high-order bits that don't map to POSIX chmod(2) bit positions.

https://github.com/podman-container-tools/container-libs/pull/935

--- vendor/go.podman.io/storage/pkg/archive/archive_bsd.go.orig	2025-06-28 00:00:00 UTC
+++ vendor/go.podman.io/storage/pkg/archive/archive_bsd.go
@@ -9,10 +9,26 @@ import (
 	"golang.org/x/sys/unix"
 )

+// syscallMode maps a Go os.FileMode to chmod(2) bits, preserving the
+// setuid/setgid/sticky bits that a raw uint32(FileMode) cast silently drops.
+func syscallMode(i os.FileMode) (o uint32) {
+	o = uint32(i.Perm())
+	if i&os.ModeSetuid != 0 {
+		o |= unix.S_ISUID
+	}
+	if i&os.ModeSetgid != 0 {
+		o |= unix.S_ISGID
+	}
+	if i&os.ModeSticky != 0 {
+		o |= unix.S_ISVTX
+	}
+	return o
+}
+
 func handleLChmod(hdr *tar.Header, path string, hdrInfo os.FileInfo, forceMask *os.FileMode) error {
 	permissionsMask := hdrInfo.Mode()
 	if forceMask != nil {
 		permissionsMask = *forceMask
 	}
-	return unix.Fchmodat(unix.AT_FDCWD, path, uint32(permissionsMask), unix.AT_SYMLINK_NOFOLLOW)
+	return unix.Fchmodat(unix.AT_FDCWD, path, syscallMode(permissionsMask), unix.AT_SYMLINK_NOFOLLOW)
 }
