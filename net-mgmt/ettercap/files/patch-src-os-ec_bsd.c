Obtained from:	https://github.com/Ettercap/ettercap/commit/00f864d7dd2d82b640064db81aad065794b9b11b

--- src/os/ec_bsd.c.orig	2014-10-17 01:29:44.000000000 +0800
+++ src/os/ec_bsd.c	2015-02-21 19:58:20.738805431 +0800
@@ -136,7 +136,7 @@
 
    /* open the socket to work on */
    sock = socket(PF_INET, SOCK_DGRAM, 0);
-   if (sock = -1)
+   if (sock == -1)
       FATAL_ERROR("Unable to open socket on interface for MTU query\n");               
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, iface, sizeof(ifr.ifr_name));
