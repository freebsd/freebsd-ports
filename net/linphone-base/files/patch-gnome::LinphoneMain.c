
$FreeBSD$

--- gnome/LinphoneMain.c	2002/12/30 10:30:37	1.1
+++ gnome/LinphoneMain.c	2002/12/30 11:27:59
@@ -676,27 +676,49 @@
 	int sock,err,if_count,i,j=0,lo=0;
 	struct ifconf netconf;
 	char buffer[32*MAX_IF];
+	struct ifreq *ifr;
 	
 	netconf.ifc_len=32*MAX_IF;
 	netconf.ifc_buf=buffer;
 	sock=socket(PF_INET, SOCK_DGRAM,0);
 	err=ioctl(sock,SIOCGIFCONF,&netconf);
-	if (err<0) printf("Error in ioctl: %i.\n",errno);
-	close(sock);
+	if (err<0) {
+		printf("Error in ioctl: %i.\n",errno);
+		close(sock);
+		return (-1);
+	}
 	
-	if_count=netconf.ifc_len/32;
+	if_count=netconf.ifc_len/sizeof(struct ifreq);
 	printf("Found %i interfaces.\n",if_count);
 	for (i=0;i<if_count;i++)
 	{
-		if (strcmp(netconf.ifc_req[i].ifr_name,"lo")==0) lo=1;
+		ifr = &netconf.ifc_req[i];
+		err = ioctl(sock, SIOCGIFFLAGS, ifr);
+		if (err < 0) {
+			if (errno != ENXIO)
+				printf("Error in ioctl: %i.\n",errno);
+			continue;
+		}
+		if ((ifr->ifr_flags & (IFF_UP || IFF_RUNNING)) == 0)
+			continue;
+		err = ioctl(sock, SIOCGIFADDR, ifr);
+		if (err < 0) {
+                        printf("Error in ioctl: %i.\n",errno);
+                        continue;
+                }
+			
+		if (strncmp(netconf.ifc_req[i].ifr_name,"lo",2)==0) lo=1;
+		if (netconf.ifc_req[i].ifr_name[0] == '\0')
+			continue;
 
 		strncpy(lpm->net_conf.if_names[j],netconf.ifc_req[i].ifr_name,20);
 		strncpy(lpm->net_conf.if_addr[j],inet_ntoa(((struct sockaddr_in*)(&netconf.ifc_req[i].ifr_addr))->sin_addr),20);
 		j++;
 	
 	}
+	close(sock);
 	if (lo==0) return(-1);
-	return(if_count);
+	return(j);
 }
 
 static char lock_name[80];
