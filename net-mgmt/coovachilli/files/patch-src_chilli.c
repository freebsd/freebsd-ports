diff -urN src/chilli.c.orig src/chilli.c
--- src/chilli.c.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/chilli.c	2008-06-29 16:17:48.000000000 +0100
@@ -3422,7 +3422,6 @@
     exit(1);
   }
 
-  /*tun_setaddr(tun, &options.dhcplisten,  &options.net, &options.mask);*/
   tun_setaddr(tun, &options.dhcplisten,  &options.dhcplisten, &options.mask);
   tun_set_cb_ind(tun, cb_tun_ind);
 
@@ -3638,8 +3637,7 @@
     mainclock = time(0);
 
     if ((msgresult = 
-	 TEMP_FAILURE_RETRY(msgrcv(redir->msgid, (struct msgbuf *)&msg, 
-				   sizeof(msg.mdata), 0, IPC_NOWAIT)))  == -1) {
+	 TEMP_FAILURE_RETRY(msgrcv(redir->msgid, (void *)&msg, sizeof(msg.mdata), 0, IPC_NOWAIT)))  == -1) {
       if ((errno != EAGAIN) && (errno != ENOMSG))
 	log_err(errno, "msgrcv() failed!");
     }
@@ -3669,7 +3667,7 @@
 
 #elif defined (__FreeBSD__)  || defined (__APPLE__) || defined (__OpenBSD__)
 
-	if (net_isset(&dhcp->ipif, &fds) && dhcp_decaps(dhcp) < 0)
+	if (net_isset(&dhcp->ipif, &fds) && dhcp_receive(dhcp) < 0)
 	  log_err(0, "dhcp_decaps() failed!");
 
 #endif

