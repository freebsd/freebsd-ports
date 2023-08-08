--- listener/redir/tcp_freebsd.go.orig	2023-05-24 08:01:04 UTC
+++ listener/redir/tcp_freebsd.go
@@ -46,7 +46,8 @@ func parserPacket(conn net.Conn) (socks5.Addr, error) 
 func getorigdst(fd uintptr) (netip.AddrPort, error) {
 	addr := unix.RawSockaddrInet4{}
 	size := uint32(unsafe.Sizeof(addr))
-	if err := socketcall(GETSOCKOPT, fd, syscall.IPPROTO_IP, SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&addr)), uintptr(unsafe.Pointer(&size)), 0); err != nil {
+	 _, _, err := syscall.Syscall6(syscall.SYS_GETSOCKOPT, fd, syscall.IPPROTO_IP, SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&addr)), uintptr(unsafe.Pointer(&size)), 0);
+	if err != 0 {
 		return netip.AddrPort{}, err
 	}
 	port := binary.BigEndian.Uint16((*(*[2]byte)(unsafe.Pointer(&addr.Port)))[:])
@@ -56,7 +57,8 @@ func getorigdst(fd uintptr) (netip.AddrPort, error) {
 func getorigdst6(fd uintptr) (netip.AddrPort, error) {
 	addr := unix.RawSockaddrInet6{}
 	size := uint32(unsafe.Sizeof(addr))
-	if err := socketcall(GETSOCKOPT, fd, syscall.IPPROTO_IPV6, IP6T_SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&addr)), uintptr(unsafe.Pointer(&size)), 0); err != nil {
+	_, _, err := syscall.Syscall6(syscall.SYS_GETSOCKOPT, fd, syscall.IPPROTO_IPV6, IP6T_SO_ORIGINAL_DST, uintptr(unsafe.Pointer(&addr)), uintptr(unsafe.Pointer(&size)), 0);
+	if err != 0 {
 		return netip.AddrPort{}, err
 	}
 	port := binary.BigEndian.Uint16((*(*[2]byte)(unsafe.Pointer(&addr.Port)))[:])
