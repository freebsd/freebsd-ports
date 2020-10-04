--- smtpc/smtpch.c	Sat Jun 20 09:00:11 2020
+++ sm-9/mta/smtpc/smtpch.c	Thu Oct  1 10:52:53 2020
@@ -1642,7 +1646,7 @@
 		if (!IPADDR_EQ(*srvaddr, tdcnf->tlsdanecnf_ips[ui]))
 			continue;
 		tdcnf->tlsdanecnf_hn_idx = (int) ui;
-		for (d = 0; d < tdcnf->tlsdanecnf_ips_n; d++) {
+		for (d = 0; d < SM_ARRAY_SIZE(tdcnf->tlsdanecnf_pubkey_fps); d++) {
 			if (NULL == tdcnf->tlsdanecnf_pubkey_fps[d])
 				continue;
 			if (!tlsaapplies(d, tdcnf->tlsdanecnf_ip2pk[ui]))

