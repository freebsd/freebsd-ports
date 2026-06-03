--- vendor/github.com/neurlang/wayland/os/scm_freebsd.go.orig	2025-11-14 04:42:13 UTC
+++ vendor/github.com/neurlang/wayland/os/scm_freebsd.go
@@ -0,0 +1,66 @@
+//go:build freebsd
+// +build freebsd
+
+package os
+
+import "golang.org/x/sys/unix"
+import "syscall"
+
+// SocketControlMessage is a socket control message
+type SocketControlMessage = syscall.SocketControlMessage
+
+// Sockaddr is a socket address
+type Sockaddr = unix.Sockaddr
+
+// ParseSocketControlMessage calls a system call to parse a Socket Control Message
+func ParseSocketControlMessage(b []byte) ([]SocketControlMessage, error) {
+	scms, err := syscall.ParseSocketControlMessage(b)
+	return []SocketControlMessage(scms), err
+}
+
+// ParseUnixRights calls a system call to parse unix rights
+func ParseUnixRights(m *SocketControlMessage) (fds []int, err error) {
+	return syscall.ParseUnixRights(m)
+}
+
+func fallocate(fd int, mode uint32, off int64, size int64) error {
+	return syscall.Ftruncate(fd, off+size)
+}
+
+
+// UnixRights calls a system call
+func UnixRights(fd int) []byte {
+	return syscall.UnixRights(fd)
+}
+
+// Sendmsg sends information on fd using a Sendmsg system call
+func Sendmsg(fd int, msg []byte, oob []byte, sockaddr Sockaddr, z int) error {
+	return unix.Sendmsg(fd, msg, oob, sockaddr, z)
+}
+
+// Mmap calls the system call to map memory on a fd
+func Mmap(fd int, offset int64, length int, prot int, flags int) (data []byte, err error) {
+	return syscall.Mmap(fd, offset, length, prot, flags)
+}
+
+// Munmap calls the system call to unmap memory
+func Munmap(data []byte) error {
+	return syscall.Munmap(data)
+}
+
+// Close closes the fd
+func Close(fd int) error {
+	return syscall.Close(fd)
+}
+
+// ProtRead Pages may be read
+const ProtRead = syscall.PROT_READ
+
+// ProtWrite Pages may be written
+const ProtWrite = syscall.PROT_WRITE
+
+// MapShared Share this mapping
+const MapShared = syscall.MAP_SHARED
+
+// MapPrivate Private mapping
+const MapPrivate = syscall.MAP_PRIVATE
