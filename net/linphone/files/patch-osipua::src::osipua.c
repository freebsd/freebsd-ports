
$FreeBSD$

--- osipua/src/osipua.c	2003/06/13 12:25:43	1.1
+++ osipua/src/osipua.c	2003/06/13 12:58:48
@@ -595,8 +595,7 @@
 		        if (ipaddr != NULL)
 			{
 			        osip_trace(OSIP_INFO1,("osip_ua_find 1: %s <> %s \n",ua->ua_ipaddr,ipaddr));
-				if ((strcasecmp(ua->ua_ipaddr,ipaddr)==0) || (strcasecmp("127.0.0.1",ipaddr)==0) ||
-				    IN6_IS_ADDR_LOOPBACK(res->ai_addr))
+				if ((strcasecmp(ua->ua_ipaddr,ipaddr)==0) || (strcasecmp("127.0.0.1",ipaddr)==0))
 				{
 				      ret_ua=ua;       /* ip addresses match */
 				}
