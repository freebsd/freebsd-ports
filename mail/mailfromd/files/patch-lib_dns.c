From 2d91db836a95a66c7b9ad1acb9dd0ebf93fb4f44 Mon Sep 17 00:00:00 2001
From: Sergey Poznyakoff <gray@gnu.org>
Date: Fri, 23 Mar 2018 11:00:37 +0000
Subject: Fix dns_resolve_ipstr

* lib/dns.c (dns_resolve_ipstr): Select rrtype depending on the
domain in question. This should produce the same results as it was
in the previous res_query implementation, which queried for T_ANY
and selected the first RR type returned.

--- lib/dns.c.orig	2017-11-03 05:06:35 UTC
+++ lib/dns.c
@@ -438,27 +438,35 @@ dns_resolve_ipstr(const char *ipstr, const char *domai
 	int rc;
 	adns_answer *ans;
 	char *name;
-
-	if (!dns_str_is_ipv4(ipstr))
-		return dns_failure;
-	if (!domain) {
+	adns_rrtype type;
+	
+	if (!domain || strcasecmp(domain, "in-addr.arpa") == 0) {
 		IPBUF ipbuf;
+		if (!dns_str_is_ipv4(ipstr))
+			return dns_failure;
                 if (dns_reverse_ipstr(ipstr, ipbuf))
                         return dns_failure;
 		mu_asprintf(&name, "%s.in-addr.arpa", ipbuf);
+		type = adns_r_ptr_raw;
         } else {
 		mu_asprintf(&name, "%s.%s", ipstr, domain);
+		type = adns_r_a;
         }
 
-	rc = adns_synchronous(get_state(), name, adns_r_ptr_raw,
+	rc = adns_synchronous(get_state(), name, type,
 			      DEFAULT_QFLAGS,
 			      &ans);
 	free(name);
 	if (rc)
 		return errno_to_dns_status(rc);
 	status = adns_to_dns_status(ans->status);
-	if (status == dns_success)
-		*hbuf = mu_strdup(ans->rrs.str[0]);
+	if (status == dns_success) {
+		if (ans->type == adns_r_ptr_raw) {
+			*hbuf = mu_strdup(ans->rrs.str[0]);
+		} else {
+			*hbuf = mu_strdup(inet_ntoa(ans->rrs.inaddr[0]));
+		}
+	}
 	free(ans);
 	return status;
 }
