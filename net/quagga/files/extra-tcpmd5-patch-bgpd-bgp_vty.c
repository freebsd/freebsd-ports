--- bgpd/bgp_vty.c.orig	Tue Oct 12 22:06:09 2004
+++ bgpd/bgp_vty.c	Fri Jan 28 17:52:57 2005
@@ -1386,6 +1386,45 @@
        "AS number used as local AS\n"
        "Do not prepend local-as to updates from ebgp peers\n")
 
+#ifdef QUAGGA_TCP_MD5SIG
+DEFUN (neighbor_password,
+       neighbor_password_cmd,
+       NEIGHBOR_CMD2 "password WORD",
+       NEIGHBOR_STR
+       NEIGHBOR_ADDR_STR2
+       "Specify a password for TCPMD5 authentication with this peer\n")
+{
+  struct peer *peer;
+  int ret;
+
+  peer = peer_and_group_lookup_vty (vty, argv[0]);
+  if (! peer)
+    return CMD_WARNING;
+
+  ret = peer_password_set (peer, argv[1]);
+  return bgp_vty_return (vty, ret);
+}
+
+DEFUN (no_neighbor_password,
+       no_neighbor_password_cmd,
+       NO_NEIGHBOR_CMD2 "password",
+       NO_STR
+       NEIGHBOR_STR
+       NEIGHBOR_ADDR_STR2
+       "Disable TCPMD5 authentication with this peer\n")
+{
+  struct peer *peer;
+  int ret;
+
+  peer = peer_and_group_lookup_vty (vty, argv[0]);
+  if (! peer)
+    return CMD_WARNING;
+
+  ret = peer_password_unset (peer);
+  return bgp_vty_return (vty, ret);
+}
+#endif /* QUAGGA_TCP_MD5SIG */
+
 DEFUN (neighbor_activate,
        neighbor_activate_cmd,
        NEIGHBOR_CMD2 "activate",
@@ -8530,6 +8569,10 @@
   install_element (BGP_NODE, &no_neighbor_local_as_cmd);
   install_element (BGP_NODE, &no_neighbor_local_as_val_cmd);
   install_element (BGP_NODE, &no_neighbor_local_as_val2_cmd);
+
+  /* "neighbor password" commands. */
+  install_element (BGP_NODE, &neighbor_password_cmd);
+  install_element (BGP_NODE, &no_neighbor_password_cmd);
 
   /* "neighbor activate" commands. */
   install_element (BGP_NODE, &neighbor_activate_cmd);
