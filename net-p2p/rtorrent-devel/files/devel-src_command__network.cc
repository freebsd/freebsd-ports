--- src/command_network.cc.orig	2007-12-18 21:13:53.000000000 +0000
+++ src/command_network.cc	2007-12-18 21:14:26.000000000 +0000
@@ -224,6 +224,8 @@
       saPtr->set_port(port);
       control->scgi()->open_port(saPtr, saPtr->length(), rpc::call_command_value("get_scgi_dont_route"));
 
+      rak::address_info::free_address_info(ai);
+
       break;
 
     case 2:
