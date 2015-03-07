--- src/configfile.c.orig	2015-01-03 11:29:45.000000000 -0500
+++ src/configfile.c	2015-01-03 11:54:18.000000000 -0500
@@ -20,12 +20,12 @@
 
 /* chaddr to use for bootp header 'chaddr' and to construct ClientID option */
 /* optionally specified by user; if unspecified, GetChaddr() returns my_eaddr */
-struct ether_addr chaddr; 
+struct libnet_ether_addr chaddr; 
 int is_chaddr_specified; /* flag */
 
-/* ether_addr to use for ethernet frame src */
+/* libnet_ether_addr to use for ethernet frame src */
 /* optionally specified by user; if unspecified, GetEther_src() returns my_eaddr */
-struct ether_addr ether_src; 
+struct libnet_ether_addr ether_src; 
 int is_ether_src_specified; /* flag */
 
 /* An ipaddr to use for "Server Identifer" option  (when this is needed)
@@ -50,7 +50,7 @@
 int num_legal_servers;
 
 /* array of legal DHCP servers' ethersrc addresses, and number elems in array */
-struct ether_addr legal_server_ethersrcs[MAX_LEGAL_SERVER_ETHERSRCS];
+struct libnet_ether_addr legal_server_ethersrcs[MAX_LEGAL_SERVER_ETHERSRCS];
 int num_legal_server_ethersrcs;
 
 /* parallel arrays of "lease networks of concern" (address & mask), and number of elems in arrays.
@@ -85,7 +85,7 @@
 	int tokens; /* number of tokens successfully read by sscanf */
 	int tmpint;
 	unsigned int tmpuint;
-	struct ether_addr *enet;
+	struct libnet_ether_addr *enet;
 	struct in_addr inaddr, inaddr2;
 	
 	/* init all values to defaults */
@@ -420,14 +420,14 @@
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
@@ -442,14 +442,14 @@
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
@@ -555,7 +555,7 @@
 }
 
 int
-isLegalServerEthersrcsMember(struct ether_addr *eaddr)
+isLegalServerEthersrcsMember(struct libnet_ether_addr *eaddr)
 {
 /* If eaddr is a member of legal_server_ethersrcs[], return true.
    If legal_server_ethersrcs[] is empty, also return true.
@@ -576,7 +576,7 @@
 		return 1;
 
 	for (i = 0; i < num_legal_server_ethersrcs; i++) {
-		if (!bcmp(eaddr, &legal_server_ethersrcs[i], sizeof(struct ether_addr))) 
+		if (!bcmp(eaddr, &legal_server_ethersrcs[i], sizeof(struct libnet_ether_addr))) 
 			return 1; /* found */
 	}
 	return 0; /* not found */
