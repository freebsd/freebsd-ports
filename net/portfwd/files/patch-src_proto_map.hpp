--- src/proto_map.hpp.orig	Sat Jan 27 11:45:32 2007
+++ src/proto_map.hpp	Sat Jan 27 11:46:08 2007
@@ -16,8 +16,8 @@
 private:
   vector<int>       *port_list;
   vector<host_map*> *map_list;
-  int               ftp_actv;
-  int               ftp_pasv;
+  long              ftp_actv;
+  long              ftp_pasv;
   struct ip_addr    actv_ip;
   struct ip_addr    pasv_ip;
   int               uid;
