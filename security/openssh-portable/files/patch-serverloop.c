Fix CVE-2016-10010


--- serverloop.c.orig	2016-07-27 17:54:27.000000000 -0500
+++ serverloop.c	2017-01-11 18:44:42.881227000 -0600
@@ -999,7 +999,7 @@
 
 	/* XXX fine grained permissions */
 	if ((options.allow_streamlocal_forwarding & FORWARD_LOCAL) != 0 &&
-	    !no_port_forwarding_flag) {
+	    !no_port_forwarding_flag && use_privsep) {
 		c = channel_connect_to_path(target,
 		    "direct-streamlocal@openssh.com", "direct-streamlocal");
 	} else {
@@ -1280,7 +1280,7 @@
 
 		/* check permissions */
 		if ((options.allow_streamlocal_forwarding & FORWARD_REMOTE) == 0
-		    || no_port_forwarding_flag) {
+		    || no_port_forwarding_flag || !use_privsep) {
 			success = 0;
 			packet_send_debug("Server has disabled port forwarding.");
 		} else {
