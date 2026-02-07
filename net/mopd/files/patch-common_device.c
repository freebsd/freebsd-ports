--- common/device.c.orig	1996-08-08 00:01:54 UTC
+++ common/device.c
@@ -35,7 +35,7 @@ static char rcsid[] = "$Id: device.c,v 1.21 1996/08/08
 #include "common/common.h"
 #include "common/mopdef.h"
 
-struct	if_info *iflist;		/* Interface List		*/
+/*extern*/ struct if_info *iflist;		/* Interface List		*/
 
 void mopReadDL();
 void mopReadRC();
@@ -111,7 +111,8 @@ deviceOpen(ifname, proto, trans)
 {
 	struct if_info *p, tmp;
 
-	strcpy(tmp.if_name,ifname);
+	strncpy(tmp.if_name,ifname,sizeof(tmp.if_name) - 1);
+	tmp.if_name[sizeof(tmp.if_name) - 1] = 0;
 	tmp.iopen   = pfInit;
 	
 	switch (proto) {
@@ -138,7 +139,8 @@ deviceOpen(ifname, proto, trans)
 		p->next = iflist;
 		iflist = p;
 
-		strcpy(p->if_name,tmp.if_name);
+		strncpy(p->if_name,tmp.if_name, IFNAME_SIZE -1);
+		p->if_name[IFNAME_SIZE -1] = 0;
 		p->iopen   = tmp.iopen;
 		p->write   = pfWrite;
 		p->read    = tmp.read;
@@ -185,12 +187,12 @@ deviceInitOne(ifname)
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
