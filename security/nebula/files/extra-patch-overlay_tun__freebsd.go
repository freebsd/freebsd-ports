The syscall.Iovec struct has differently typed fields depending on the
word size of the architecture.  This patch fixes the build on 32 bit
platforms but is incorrect on 64 bit platforms.

See also https://stackoverflow.com/q/79966298/417501

--- overlay/tun_freebsd.go.orig	2026-06-24 11:24:23 UTC
+++ overlay/tun_freebsd.go
@@ -107,7 +107,7 @@ func (t *tun) Read(to []byte) (int, error) {
 
 	iovecs := []syscall.Iovec{
 		{&head[0], 4},
-		{&to[0], uint64(len(to))},
+		{&to[0], uint32(len(to))},
 	}
 
 	n, _, errno := syscall.Syscall(syscall.SYS_READV, uintptr(t.devFd), uintptr(unsafe.Pointer(&iovecs[0])), uintptr(2))
@@ -151,7 +151,7 @@ func (t *tun) Write(from []byte) (int, error) {
 	}
 	iovecs := []syscall.Iovec{
 		{&head[0], 4},
-		{&from[0], uint64(len(from))},
+		{&from[0], uint32(len(from))},
 	}
 
 	n, _, errno := syscall.Syscall(syscall.SYS_WRITEV, uintptr(t.devFd), uintptr(unsafe.Pointer(&iovecs[0])), uintptr(2))
