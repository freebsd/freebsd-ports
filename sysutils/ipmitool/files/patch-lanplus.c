--- src/plugins/lanplus/lanplus.c.orig	Fri Apr 21 09:34:30 2006
+++ src/plugins/lanplus/lanplus.c	Thu Jan 18 21:12:54 2007
@@ -2456,7 +2456,7 @@
 {
 	struct ipmi_rs * rsp = ipmi_lan_poll_recv(intf);
 	
-   if(rsp->session.authtype != 0)
+   if(rsp != NULL && rsp->session.authtype != 0)
    {
    	ack_sol_packet(intf, rsp);	              
 
