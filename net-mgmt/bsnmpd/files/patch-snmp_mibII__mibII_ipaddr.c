--- snmp_mibII/mibII_ipaddr.c.orig	Wed Sep 21 12:21:53 2005
+++ snmp_mibII/mibII_ipaddr.c	Wed Sep 21 12:18:56 2005
@@ -88,8 +88,10 @@
 	}
 
 	bcast.s_addr = upd->addr.s_addr & upd->mask.s_addr;
-	if (!(upd->set & UPD_BCAST) || upd->bcast)
-		bcast.s_addr |= htonl(0xffffffff & ~ntohl(upd->mask.s_addr));
+	if (!(upd->set & UPD_BCAST) || upd->bcast) {
+		uint32_t tmp = ~ntohl(upd->mask.s_addr);
+		bcast.s_addr |= htonl(0xffffffff & tmp);
+	}
 
 	if ((ifa = mib_create_ifa(upd->ifindex, upd->addr, upd->mask, bcast)) == NULL)
 		return (SNMP_ERR_GENERR);
