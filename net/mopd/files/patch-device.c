--- common/device.c	1996/09/21 13:49:16	1.1
+++ common/device.c	2000/02/20 17:45:33	1.4
@@ -111,7 +113,8 @@
 {
 	struct if_info *p, tmp;
 
-	strcpy(tmp.if_name,ifname);
+	strncpy(tmp.if_name,ifname,sizeof(tmp.if_name) - 1);
+	tmp.if_name[sizeof(tmp.if_name) - 1] = 0;
 	tmp.iopen   = pfInit;
 	
 	switch (proto) {
@@ -138,7 +141,8 @@
 		p->next = iflist;
 		iflist = p;
 
-		strcpy(p->if_name,tmp.if_name);
+		strncpy(p->if_name,tmp.if_name, IFNAME_SIZE -1);
+		p->if_name[IFNAME_SIZE -1] = 0;
 		p->iopen   = tmp.iopen;
 		p->write   = pfWrite;
 		p->read    = tmp.read;
@@ -185,12 +199,12 @@
 	if ((strlen(dev) == 2) &&
 	    (dev[0] == 'e') &&
 	    ((dev[1] == 'n') || (dev[1] == 't'))) {
-		sprintf(interface,"ent%d\0",unit);
+		snprintf(interface,sizeof(interface),"ent%d\0",unit);
 	} else {
-		sprintf(interface,"%s%d\0",dev,unit);
+		snprintf(interface,sizeof(interface),"%s%d\0",dev,unit);
 	}
 #else
-	sprintf(interface,"%s",ifname);
+	snprintf(interface,sizeof(interface),"%s",ifname);
 #endif /* _AIX */
 
 	/* Ok, init it just once */
