--- fea/data_plane/io/io_ip_socket.cc.orig	2018-07-10 15:49:50 UTC
+++ fea/data_plane/io/io_ip_socket.cc
@@ -2293,10 +2293,10 @@ IoIpSocket::send_packet(const string& if
 	    //
 	    struct sockaddr_in sin;
 	    src_address.copy_out(sin);
-	    if (bind(_proto_socket_out,
+	    bind(_proto_socket_out,
 		     reinterpret_cast<struct sockaddr*>(&sin),
-		     sizeof(sin))
-		< 0) {
+		     sizeof(sin));
+		if ( reinterpret_cast<struct sockaddr*>(&sin) < ((void*)0)) {
 		error_msg = c_format("raw socket bind(%s) failed: %s",
 				     cstring(src_address), XSTRERROR);
 		XLOG_ERROR("%s", error_msg.c_str());
