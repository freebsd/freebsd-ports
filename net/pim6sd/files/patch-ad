--- pim6sd/mld6v2.h	5 Sep 2002 08:12:23 -0000	1.6
+++ pim6sd/mld6v2.h	16 Nov 2002 15:14:01 -0000
@@ -67,12 +67,10 @@
 #define nmcastrcd mldv2_hdr.icmp6_data16[1]
 
 struct mld_report_hdr {	/* Multicast Report */
-    u_int8_t  mld_type;	/* Multicast Report Type */
-    u_int8_t  mld_reserved1;	/* Reserved */
-    u_int16_t mld_cksum;	/* Checksum */
-    u_int16_t mld_reserved2;	/* Reserved */
-    u_int16_t mld_grpnum;	/* Number of Multicast Address Records */
+    struct icmp6_hdr	mld_icmp6_hdr;	/* version & type of MLD message */
 };
+
+#define mld_grpnum	mld_icmp6_hdr.icmp6_data16[1]
 #endif
 
 #ifndef MLD_MINLEN
