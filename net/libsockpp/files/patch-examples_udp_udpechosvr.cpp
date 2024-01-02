--- examples/udp/udpechosvr.cpp.orig	2023-12-17 20:26:10 UTC
+++ examples/udp/udpechosvr.cpp
@@ -72,7 +72,7 @@ void run_echo(UDPSOCK sock)
 	// Read some data, also getting the address of the sender,
 	// then just send it back.
 	while ((n = sock.recv_from(buf, sizeof(buf), &srcAddr)) > 0)
-		sock.send_to(buf, n, srcAddr);
+		sock.send_to((void*)buf, n, srcAddr);
 }
 
 // --------------------------------------------------------------------------
