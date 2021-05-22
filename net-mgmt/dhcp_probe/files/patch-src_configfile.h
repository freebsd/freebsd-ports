--- src/configfile.h.orig	2021-01-18 19:16:10 UTC
+++ src/configfile.h
@@ -6,14 +6,14 @@
 int read_configfile(const char *fname);
 
 /* accessor functions for all the configuration file data */
-struct ether_addr * GetChaddr (void);
-struct ether_addr * GetEther_src (void);
+struct libnet_ether_addr * GetChaddr (void);
+struct libnet_ether_addr * GetEther_src (void);
 struct in_addr * GetClient_ip_address(void);
 struct in_addr * GetServer_id(void);
 unsigned GetCycle_time(void);
 int GetResponse_wait_time(void);
 int isLegalServersMember(struct in_addr *ipaddr);
-int isLegalServerEthersrcsMember(struct ether_addr *eaddr);
+int isLegalServerEthersrcsMember(struct libnet_ether_addr *eaddr);
 int isInLeaseNetworksOfConcern(struct in_addr *ipaddr);
 int GetDo_not_lookup_enet_and_ip_addresses(void);
 
