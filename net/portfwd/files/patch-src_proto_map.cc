--- src/proto_map.cc.orig	Sat Jan 27 11:44:09 2007
+++ src/proto_map.cc	Sat Jan 27 11:46:42 2007
@@ -16,11 +16,11 @@
   map_list   = map_l;
   fragile    = 0; /* false */
 
-  ftp_actv   = (int) actv;
+  ftp_actv   = (long) actv;
   if (ftp_actv)
     actv_ip = *actv;
 
-  ftp_pasv   = (int) pasv;
+  ftp_pasv   = (long) pasv;
   if (ftp_pasv)
     pasv_ip = *pasv;
 
