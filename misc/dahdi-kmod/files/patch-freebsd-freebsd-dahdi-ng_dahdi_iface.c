--- freebsd/freebsd/dahdi/ng_dahdi_iface.c	(revision 10746)
+++ freebsd/freebsd/dahdi/ng_dahdi_iface.c	(revision 10747)
@@ -281,10 +281,14 @@
 	/* connect other hooks */
 	dahdi_iface_connect_node_path(node, DAHDI_IFACE_HOOK_UPPER,
 	    NG_CISCO_HOOK_INET, NG_CISCO_HOOK_INET6, NG_IFACE_HOOK_INET6);
+#if __FreeBSD_version < 1100013
 	dahdi_iface_connect_node_path(node, DAHDI_IFACE_HOOK_UPPER,
 	    NG_CISCO_HOOK_INET, NG_CISCO_HOOK_APPLETALK, NG_IFACE_HOOK_ATALK);
+#endif
+#if __FreeBSD_version < 1100012
 	dahdi_iface_connect_node_path(node, DAHDI_IFACE_HOOK_UPPER,
 	    NG_CISCO_HOOK_INET, NG_CISCO_HOOK_IPX, NG_IFACE_HOOK_IPX);
+#endif
 
 	/* get iface name */
 	NG_MKMESSAGE(msg, NGM_IFACE_COOKIE, NGM_IFACE_GET_IFNAME, 0, M_WAITOK);
