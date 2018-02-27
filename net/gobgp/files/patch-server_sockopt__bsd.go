--- server/sockopt_bsd.go.orig	2018-02-09 18:45:37 UTC
+++ server/sockopt_bsd.go
@@ -23,13 +23,12 @@ import (
 )
 
 const (
-	TCP_MD5SIG       = 0x10 // TCP MD5 Signature (RFC2385)
 	IPV6_MINHOPCOUNT = 73   // Generalized TTL Security Mechanism (RFC5082)
 )
 
 func setsockoptTcpMD5Sig(fd int, address string, key string) error {
 	// always enable and assumes that the configuration is done by setkey()
-	return os.NewSyscallError("setsockopt", syscall.SetsockoptInt(fd, syscall.IPPROTO_TCP, TCP_MD5SIG, 1))
+	return os.NewSyscallError("setsockopt", syscall.SetsockoptInt(fd, syscall.IPPROTO_TCP, syscall.TCP_MD5SIG, 1))
 }
 
 func setTcpMD5SigSockopt(l *net.TCPListener, address string, key string) error {
