--- src/configfile.c.orig	2021-01-18 19:18:05 UTC
+++ src/configfile.c
@@ -21,13 +21,13 @@
 /* chaddr to use for bootp header 'chaddr' and to construct ClientID option */
 /* optionally specified by user; if unspecified, GetChaddr() returns my_eaddr */
 /* Is required if do_not_lookup_enet_and_ip_addresses is also specifed. */
-struct ether_addr chaddr; 
+struct libnet_ether_addr chaddr; 
 int is_chaddr_specified; /* flag */
 
-/* ether_addr to use for ethernet frame src */
+/* libnet_ether_addr to use for ethernet frame src */
 /* optionally specified by user; if unspecified, GetEther_src() returns my_eaddr */
 /* Is required if do_not_lookup_enet_and_ip_addresses is also specifed. */
-struct ether_addr ether_src; 
+struct libnet_ether_addr ether_src; 
 int is_ether_src_specified; /* flag */
 
 /* An ipaddr to use for "Server Identifer" option  (when this is needed)
@@ -52,7 +52,7 @@ struct in_addr legal_servers[MAX_LEGAL_SERVERS];
 int num_legal_servers;
 
 /* array of legal DHCP servers' ethersrc addresses, and number elems in array */
-struct ether_addr legal_server_ethersrcs[MAX_LEGAL_SERVER_ETHERSRCS];
+struct libnet_ether_addr legal_server_ethersrcs[MAX_LEGAL_SERVER_ETHERSRCS];
 int num_legal_server_ethersrcs;
 
 /* parallel arrays of "lease networks of concern" (address & mask), and number of elems in arrays.
@@ -95,7 +95,7 @@ read_configfile(const char *fname)
 	int tokens; /* number of tokens successfully read by sscanf */
 	int tmpint;
 	unsigned int tmpuint;
-	struct ether_addr *enet;
+	struct libnet_ether_addr *enet;
 	struct in_addr inaddr, inaddr2;
 	int is_fatal_error;
 	
@@ -459,14 +459,14 @@ read_configfile(const char *fname)
 }
 
 
-struct ether_addr *
+struct libnet_ether_addr *
 GetChaddr (void)
 {
 /* Return copy of chaddr (if specified) else my_eaddr.
    Not re-entrant; we use static storage to hold the value address we return.
    Should not be called until global 'my_eaddr' has been init'd.
 */
-	static struct ether_addr chaddr_copy;
+	static struct libnet_ether_addr chaddr_copy;
 
 	/* we re-init the static copy on each call, since we don't know if the
 	   	caller has written into it. */
@@ -481,14 +481,14 @@ GetChaddr (void)
 }
 
 
-struct ether_addr *
+struct libnet_ether_addr *
 GetEther_src (void)
 {
 /* Return copy of ether_src (if specified) else my_eaddr.
    Not re-entrant; we use static storage to hold the value address we return.
    Should not be called until global 'my_eaddr' has been init'd.
 */
-	static struct ether_addr ether_src_copy;
+	static struct libnet_ether_addr ether_src_copy;
 
 	/* we re-init the static copy on each call, since we don't know if the
 	   	caller has written into it. */
@@ -594,7 +594,7 @@ isInLeaseNetworksOfConcern(struct in_addr *ipaddr)
 }
 
 int
-isLegalServerEthersrcsMember(struct ether_addr *eaddr)
+isLegalServerEthersrcsMember(struct libnet_ether_addr *eaddr)
 {
 /* If eaddr is a member of legal_server_ethersrcs[], return true.
    If legal_server_ethersrcs[] is empty, also return true.
@@ -615,7 +615,7 @@ isLegalServerEthersrcsMember(struct ether_addr *eaddr)
 		return 1;
 
 	for (i = 0; i < num_legal_server_ethersrcs; i++) {
-		if (!bcmp(eaddr, &legal_server_ethersrcs[i], sizeof(struct ether_addr))) 
+		if (!bcmp(eaddr, &legal_server_ethersrcs[i], sizeof(struct libnet_ether_addr))) 
 			return 1; /* found */
 	}
 	return 0; /* not found */
