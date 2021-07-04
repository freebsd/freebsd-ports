--- listener/redir/tcp_freebsd.go.orig	2021-07-04 17:12:45 UTC
+++ listener/redir/tcp_freebsd.go
@@ -38,7 +38,8 @@ func parserPacket(conn net.Conn) (socks5.Addr, error) 
 func getorigdst(fd uintptr) (socks5.Addr, error) {
 	raw := syscall.RawSockaddrInet4{}
 	siz := unsafe.Sizeof(raw)
-	if err := socketcall(GETSOCKOPT, fd, syscall.IPPROTO_IP, SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&raw)), uintptr(unsafe.Pointer(&siz)), 0); err != nil {
+	_, _, err := syscall.Syscall6(syscall.SYS_GETSOCKOPT, fd, syscall.IPPROTO_IP, SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&raw)), uintptr(unsafe.Pointer(&siz)), 0);
+	if err != 0 {
 		return nil, err
 	}
 
