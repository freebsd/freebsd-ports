diff --git getifaddr.c getifaddr.c
index 9c437b7..5eb6716 100644
--- getifaddr.c
+++ getifaddr.c
@@ -175,7 +175,7 @@ getsysaddrs(void)
 		if (p->ifa_addr && p->ifa_addr->sa_family == AF_INET)
 		{
 			addr_in = (struct sockaddr_in *)p->ifa_addr;
-			if (p->ifa_flags & (IFF_LOOPBACK | IFF_SLAVE))
+			if (p->ifa_flags & (IFF_LOOPBACK))
 				continue;
 			memcpy(&lan_addr[n_lan_addr].addr, &addr_in->sin_addr, sizeof(lan_addr[n_lan_addr].addr));
 			if (!inet_ntop(AF_INET, &addr_in->sin_addr, lan_addr[n_lan_addr].str, sizeof(lan_addr[0].str)) )
