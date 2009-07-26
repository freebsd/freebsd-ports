--- wispy_hw_dbx.c.orig	2009-07-26 13:55:31.000000000 +0200
+++ wispy_hw_dbx.c	2009-07-26 13:55:57.000000000 +0200
@@ -624,16 +624,12 @@ int wispydbx_usb_getpollfd(wispy_phy *ph
 	return auxptr->sockpair[0];
 }
 
-extern int usb_debug;
-
 int wispydbx_usb_open(wispy_phy *phydev) {
 	int pid_status;
 	struct usb_dev_handle *wispy;
 	wispydbx_usb_aux *auxptr = (wispydbx_usb_aux *) phydev->auxptr;
 	wispydbx_startsweep startcmd;
 
-	usb_debug = 1024;
-
 	/* Make the client/server socketpair */
 	if (socketpair(PF_UNIX, SOCK_DGRAM, 0, auxptr->sockpair) < 0) {
 		snprintf(phydev->errstr, WISPY_ERROR_MAX,
