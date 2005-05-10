--- mDNSPosix/mDNSUNP.c.orig	Fri Apr  8 23:43:59 2005
+++ mDNSPosix/mDNSUNP.c	Tue May 10 21:16:46 2005
@@ -331,7 +331,7 @@
         ifr = (struct ifreq *) ptr;
 
 		len = GET_SA_LEN(ifr->ifr_addr);
-		ptr += sizeof(struct ifreq); /* for next one in buffer */
+		ptr += sizeof(ifr->ifr_name) + len; /* for next one in buffer */
     
 //        fprintf(stderr, "intf %d name=%s AF=%d\n", index, ifr->ifr_name, ifr->ifr_addr.sa_family);
         
