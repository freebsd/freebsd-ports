--- Milter.pm.orig	2001-10-10 04:21:22 UTC
+++ Milter.pm
@@ -423,10 +423,10 @@ calls. See B<Milter Context Functions> f
 =item B<connect_callback> CTX, HOSTNAME, SOCKADDR_IN
 
 Invoked on each connection. HOSTNAME is the host domain name, as determined by
-a reverse lookup on the host address. SOCKADDR_IN is the AF_INET portion of the
-host address, as determined by a B<getpeername(2)> syscall on the SMTP
-socket. You can use B<Socket::unpack_sockaddr_in()> to unpack it into a port
-and IP address.
+a reverse lookup on the host address. SOCKADDR_IN is the AF_INET or AF_INET6
+portion of the host address, as determined by a B<getpeername(2)> syscall on
+the SMTP socket. You can use B<Socket::unpack_sockaddr_in()> or
+B<Socket6::unpack_sockaddr_in6()> to unpack it into a port and IP address.
 
 This callback should return one of the B<SMFIS_*> result codes.
 
