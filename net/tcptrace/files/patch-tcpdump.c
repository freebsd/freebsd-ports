--- tcpdump.c.orig	2013-07-01 18:43:14 UTC
+++ tcpdump.c
@@ -68,9 +68,6 @@ static char const GCC_UNUSED rcsid[] =
 
 
 
-/* external ref, in case missing in older version */
-extern int pcap_offline_read(void *, int, pcap_handler, u_char *);
-
 /* global pointer, the pcap info header */
 static pcap_t *pcap;
 
@@ -114,10 +111,13 @@ static int callback(
 	/* for some reason, the windows version of tcpdump is using */
 	/* this.  It looks just like ethernet to me */
       case PCAP_DLT_EN10MB:
-	offset = find_ip_eth(buf); /* Here we check if we are dealing with Straight Ethernet encapsulation or PPPoE */
+	offset = find_ip_eth(buf); /* Here we check if we are dealing with Straight Ethernet encapsulation, PPPoE or .1q VLAN encapsulation */
 	memcpy(&eth_header, buf, EH_SIZE); /* save ether header */
 	switch (offset)
 	{
+		case EH_SIZE + ETHER_VLAN_ENCAP_LEN:
+			memcpy(&eth_header.ether_type, buf+EH_SIZE+2, 2);
+			/* FALLTHROUGH */
 		case EH_SIZE: /* straight Ethernet encapsulation */
 			memcpy((char *)ip_buf,buf+offset,iplen-offset);
 			callback_plast = ip_buf+iplen-offset-1;
@@ -250,7 +250,7 @@ pread_tcpdump(
     int ret;
 
     while (1) {
-	if ((ret = pcap_offline_read(pcap,1,(pcap_handler)callback,0)) != 1) {
+	if ((ret = pcap_dispatch(pcap,1,(pcap_handler)callback,0)) != 1) {
 	    /* prob EOF */
 
 	    if (ret == -1) {
