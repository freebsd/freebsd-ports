--- examples/unix/undgramechosvr.cpp.orig	2023-12-17 20:26:10 UTC
+++ examples/unix/undgramechosvr.cpp
@@ -86,7 +86,7 @@ int main(int argc, char* argv[])
 	// Read some data, also getting the address of the sender,
 	// then just send it back.
 	while ((n = sock.recv_from(buf, sizeof(buf), &srcAddr)) > 0)
-		sock.send_to(buf, n, srcAddr);
+		sock.send_to((void*)buf, n, srcAddr);
 
 	return 0;
 }
