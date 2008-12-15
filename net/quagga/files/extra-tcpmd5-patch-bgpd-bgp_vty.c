--- bgpd/bgp_vty.c.orig	2008-09-11 09:46:49.000000000 +0400
+++ bgpd/bgp_vty.c	2008-12-15 19:53:51.000000000 +0300
@@ -1482,13 +1482,13 @@
        "AS number used as local AS\n"
        "Do not prepend local-as to updates from ebgp peers\n")
 
+#ifdef QUAGGA_TCP_MD5SIG
 DEFUN (neighbor_password,
        neighbor_password_cmd,
-       NEIGHBOR_CMD2 "password LINE",
+       NEIGHBOR_CMD2 "password WORD",
        NEIGHBOR_STR
        NEIGHBOR_ADDR_STR2
-       "Set a password\n"
-       "The password\n")
+       "Specify a password for TCPMD5 authentication with this peer\n")
 {
   struct peer *peer;
   int ret;
@@ -1507,7 +1507,7 @@
        NO_STR
        NEIGHBOR_STR
        NEIGHBOR_ADDR_STR2
-       "Set a password\n")
+       "Disable TCPMD5 authentication with this peer\n")
 {
   struct peer *peer;
   int ret;
@@ -1519,6 +1519,7 @@
   ret = peer_password_unset (peer);
   return bgp_vty_return (vty, ret);
 }
+#endif /* QUAGGA_TCP_MD5SIG */
 
 DEFUN (neighbor_activate,
        neighbor_activate_cmd,
@@ -8942,6 +8943,10 @@
   install_element (BGP_NODE, &neighbor_password_cmd);
   install_element (BGP_NODE, &no_neighbor_password_cmd);
 
+  /* "neighbor password" commands. */
+  install_element (BGP_NODE, &neighbor_password_cmd);
+  install_element (BGP_NODE, &no_neighbor_password_cmd);
+
   /* "neighbor activate" commands. */
   install_element (BGP_NODE, &neighbor_activate_cmd);
   install_element (BGP_IPV4_NODE, &neighbor_activate_cmd);
