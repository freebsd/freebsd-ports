--- util.c.orig	Thu Dec 16 20:13:26 2004
+++ util.c	Sun Jan 16 12:05:04 2005
@@ -494,7 +494,8 @@
     if(!strcmp(ii->name,device))
       if(iface_if_getinfo(ii) & IFACE_INFO_UP) {
 	/* Allocate memory for IPv6 addresses*/
-	count = iface_if_addrcount(ii, AF_INET6);
+	if ((count = iface_if_addrcount(ii, AF_INET6)) == 0)
+		return NULL;
 	if(count == 0) break;
 	addrs = (NtopIfaceAddr *)calloc(count, sizeof(NtopIfaceAddr));
 	addr_pos = 0;
