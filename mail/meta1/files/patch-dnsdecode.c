--- libdns/dnsdecode.c	Sun Jun 11 07:09:35 2023
+++ libdns/dnsdecode.c
@@ -457,6 +457,8 @@
 	     dns_rese = dns_rese_next)
 	{
 		dns_rese_next = DRESL_NEXT(dns_rese);
+		if (T_MX != dns_rese->dnsrese_type)
+			continue;
 		if (strcasecmp((const char *) mxhost,
 			(const char *) sm_cstr_data(dns_rese->dnsrese_val.dnsresu_name))
 		    == 0)

