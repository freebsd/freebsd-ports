--- rdnssd/rdnssd.h.orig    2011-07-23 01:03:38.000000000 +0400
+++ rdnssd/rdnssd.h 2011-07-23 01:03:56.000000000 +0400
@@ -32,15 +32,6 @@
 /* Belongs in <netinet/icmp6.h> */
 #define ND_OPT_RDNSS 25
 
-struct nd_opt_rdnss
-{
-	uint8_t nd_opt_rdnss_type;
-	uint8_t nd_opt_rdnss_len;
-	uint16_t nd_opt_rdnss_resserved1;
-	uint32_t nd_opt_rdnss_lifetime;
-	/* followed by one or more IPv6 addresses */
-};
-
 # ifdef __cplusplus
 extern "C" {
 # endif
