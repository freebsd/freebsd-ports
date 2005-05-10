--- ../libipsec/pfkey_dump.c.orig	Mon Jan 31 17:25:28 2005
+++ ../libipsec/pfkey_dump.c	Tue May 10 13:00:38 2005
@@ -532,7 +532,7 @@ str_prefport(family, pref, port, ulp)
 	else
 		snprintf(prefbuf, sizeof(prefbuf), "/%u", pref);
 
-	if (ulp == IPPROTO_ICMPV6 || ulp == IPPROTO_MH)
+	if (ulp == IPPROTO_ICMPV6)
 		memset(portbuf, 0, sizeof(portbuf));
 	else {
 		if (port == IPSEC_PORT_ANY)
@@ -570,8 +570,6 @@
 			else
 				printf("%u", ulp);
 
-			if (ulp == IPPROTO_MH && p1 != 0)
-				printf(" %u", p1);
 			endprotoent();
 			break;
 		}
