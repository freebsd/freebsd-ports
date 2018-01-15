--- dns.c.orig	2005-07-17 19:55:13.000000000 -0500
+++ dns.c	2015-01-21 13:58:59.000000000 -0600
@@ -58,25 +58,48 @@
 
 int dns_query_rr_a(const res_state statp, char *fmt, ...)
 {	va_list	vl;
-	int	x,rc = 0;
-	char	*hn = NULL;
+	int	x, haveRR = 0;
+	char	*hostName = NULL;
 
 	va_start(vl,fmt);
 	if(fmt != NULL && *fmt)
 	{
-		x = vasprintf(&hn,fmt,vl);
-		if(hn != NULL && x > 0)
-		{	u_char	packet[NS_PACKETSZ];
+		x = vasprintf(&hostName,fmt,vl);
+		if(hostName != NULL && x > 0)
+		{	u_char	ns_packet[NS_PACKETSZ];
 
-			rc = (res_nquery(statp, hn,ns_c_in,ns_t_a,packet,sizeof(packet)) == -1 ? 0 : 1);
+			haveRR = (res_nquery(statp, hostName, ns_c_in, ns_t_a, ns_packet, sizeof(ns_packet)) == -1 ? 0 : 1);
 		}
 
-		if(hn != NULL)
-			free(hn);
+		if(hostName != NULL)
+			free(hostName);
 	}
 	va_end(vl);
 
-	return(rc);
+	return haveRR;
+}
+
+int dns_query_rr_aaaa(const res_state statp, char *fmt, ...)
+{	va_list	vl;
+	int	x, haveRR = 0;
+	char	*hostName = NULL;
+
+	va_start(vl,fmt);
+	if(fmt != NULL && *fmt)
+	{
+		x = vasprintf(&hostName,fmt,vl);
+		if(hostName != NULL && x > 0)
+		{	u_char	ns_packet[NS_PACKETSZ];
+
+			haveRR = (res_nquery(statp, hostName, ns_c_in, ns_t_aaaa, ns_packet, sizeof(ns_packet)) == -1 ? 0 : 1);
+		}
+
+		if(hostName != NULL)
+			free(hostName);
+	}
+	va_end(vl);
+
+	return haveRR;
 }
 
 int dns_rdnsbl_has_rr_a(const res_state statp, long ip, char *domain)
