
$FreeBSD$

--- zebra/ioctl.c.orig	Tue Oct 23 11:31:29 2001
+++ zebra/ioctl.c	Fri Oct  4 19:45:04 2002
@@ -349,6 +349,7 @@
   int ret;
   struct ifreq ifreq;
 
+  bzero(&ifreq, sizeof(struct ifreq));
   ifreq_set_name (&ifreq, ifp);
 
   ifreq.ifr_flags = ifp->flags;
@@ -371,6 +372,7 @@
   int ret;
   struct ifreq ifreq;
 
+  bzero(&ifreq, sizeof(struct ifreq));
   ifreq_set_name (&ifreq, ifp);
 
   ifreq.ifr_flags = ifp->flags;
@@ -473,6 +475,9 @@
   mask.sin6_len = sizeof (struct sockaddr_in6);
 #endif
   memcpy (&addreq.ifra_prefixmask, &mask, sizeof (struct sockaddr_in6));
+
+  addreq.ifra_lifetime.ia6t_vltime = 0xffffffff;
+  addreq.ifra_lifetime.ia6t_pltime = 0xffffffff;
   
   addreq.ifra_lifetime.ia6t_pltime = ND6_INFINITE_LIFETIME; 
   addreq.ifra_lifetime.ia6t_vltime = ND6_INFINITE_LIFETIME; 
