--- util.c.orig	Thu Oct 28 03:00:09 2004
+++ util.c	Thu Oct 28 02:58:27 2004
@@ -453,7 +453,8 @@
     if(!strcmp(ii->name,device))
       if(iface_if_getinfo(ii) & IFACE_INFO_UP) {
 	/* Allocate memory for IPv6 addresses*/
-	count = iface_if_addrcount(ii, AF_INET6);
+	if ((count = iface_if_addrcount(ii, AF_INET6)) == 0)
+	    return NULL;
 	addrs = (NtopIfaceAddr *)calloc(count, sizeof(NtopIfaceAddr));
 	addr_pos = 0;
 	for(ia = iface_getaddr_first(ii, AF_INET6) ; ia ;
