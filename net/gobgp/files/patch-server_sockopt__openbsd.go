--- server/sockopt_openbsd.go.orig	2018-02-09 18:45:43 UTC
+++ server/sockopt_openbsd.go
@@ -348,12 +348,11 @@ func saDelete(address string) error {
 }
 
 const (
-	TCP_MD5SIG       = 0x4 // TCP MD5 Signature (RFC2385)
 	IPV6_MINHOPCOUNT = 73  // Generalized TTL Security Mechanism (RFC5082)
 )
 
 func setsockoptTcpMD5Sig(fd int, address string, key string) error {
-	if err := syscall.SetsockoptInt(fd, syscall.IPPROTO_TCP, TCP_MD5SIG, 1); err != nil {
+	if err := syscall.SetsockoptInt(fd, syscall.IPPROTO_TCP, syscall.TCP_MD5SIG, 1); err != nil {
 		return os.NewSyscallError("setsockopt", err)
 	}
 	if len(key) > 0 {
