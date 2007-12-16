--- wire/client.c	(revision 5082)
+++ wire/client.c	(revision 5145)
@@ -216,13 +216,20 @@
 		
 		wi_address_set_port(address, port);
 		
-		socket = wi_socket_init_with_address(wi_socket_alloc(), address, WI_SOCKET_TCP);
+		socket = wi_autorelease(wi_socket_init_with_address(wi_socket_alloc(), address, WI_SOCKET_TCP));
+		
+		if(!socket) {
+			wr_printf_prefix(WI_STR("Could not open a socket to %@: %m"), ip);
+			
+			continue;
+		}
+		
 		wi_socket_set_interactive(socket, true);
 		
 		if(!wi_socket_connect(socket, wr_socket_context, 10.0)) {
 			wr_printf_prefix(WI_STR("Could not connect to %@: %m"), ip);
 
-			goto next;
+			continue;
 		}
 
 		wr_printf_prefix(WI_STR("Connected using %@/%@/%u bits, logging in..."),
@@ -241,11 +248,7 @@
 		wr_runloop_add_socket(wr_socket, &wr_runloop_server_callback);
 		wr_send_command(WI_STR("HELLO"));
 
-next:
-		wi_release(socket);
-		
-		if(wr_connected)
-			break;
+		break;
 	}
 
 	if(wr_socket)
