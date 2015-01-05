--- xymonnet/dns2.c.orig	2015-01-05 13:46:32 UTC
+++ xymonnet/dns2.c
@@ -472,7 +472,7 @@ static const unsigned char *display_rr(c
 		/* The RR data is a 16-byte IPv6 address. */
 		if (dlen != 16) return NULL;
 		memcpy(&addr6, aptr, sizeof(struct in6_addr));
-		addtobuffer_many(response->msgbuf, "\t", inet_ntop(AF_INET6,&addr6,msg,sizeof(msg)) );
+		addtobuffer_many(response->msgbuf, "\t", inet_ntop(AF_INET6,&addr6,msg,sizeof(msg)), NULL);
 		break;
 
 	  case T_WKS:
