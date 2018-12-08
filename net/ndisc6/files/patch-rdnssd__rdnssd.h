--- rdnssd/rdnssd.h.orig	2011-10-17 15:35:11 UTC
+++ rdnssd/rdnssd.h
@@ -32,24 +32,6 @@ extern const rdnss_src_t rdnss_netlink, 
 #define ND_OPT_RDNSS 25
 #define ND_OPT_DNSSL 31
 
-struct nd_opt_rdnss
-{
-	uint8_t nd_opt_rdnss_type;
-	uint8_t nd_opt_rdnss_len;
-	uint16_t nd_opt_rdnss_reserved;
-	uint32_t nd_opt_rdnss_lifetime;
-	/* followed by one or more IPv6 addresses */
-};
-
-struct nd_opt_dnssl
-{
-	uint8_t nd_opt_dnssl_type;
-	uint8_t nd_opt_dnssl_len;
-	uint16_t nd_opt_dnssl_reserved;
-	uint32_t nd_opt_dnssl_lifetime;
-	/* followed by one or more domain names */
-};
-
 # ifdef __cplusplus
 extern "C" {
 # endif
