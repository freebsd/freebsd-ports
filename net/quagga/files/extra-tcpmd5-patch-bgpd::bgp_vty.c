--- bgpd/bgp_vty.c.orig	Fri Oct 24 19:49:09 2003
+++ bgpd/bgp_vty.c	Mon Jan  5 08:34:08 2004
@@ -1352,6 +1352,45 @@
        "AS number used as local AS\n"
        "Do not prepend local-as to updates from ebgp peers\n")
 
+#ifdef TCP_MD5SIG
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
+#endif /* TCP_MD5SIG */
+
 DEFUN (neighbor_activate,
        neighbor_activate_cmd,
        NEIGHBOR_CMD2 "activate",
@@ -7857,6 +7896,10 @@
   install_element (BGP_NODE, &no_neighbor_local_as_cmd);
   install_element (BGP_NODE, &no_neighbor_local_as_val_cmd);
   install_element (BGP_NODE, &no_neighbor_local_as_val2_cmd);
+
+  /* "neighbor password" commands. */
+  install_element (BGP_NODE, &neighbor_password_cmd);
+  install_element (BGP_NODE, &no_neighbor_password_cmd);
 
   /* "neighbor activate" commands. */
   install_element (BGP_NODE, &neighbor_activate_cmd);
