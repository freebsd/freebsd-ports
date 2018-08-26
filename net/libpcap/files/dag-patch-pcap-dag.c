--- pcap-dag.c.orig	2018-08-26 13:02:37 UTC
+++ pcap-dag.c
@@ -1103,7 +1103,7 @@ dag_findalldevs(pcap_if_list_t *devlistp
 	char dagname[DAGNAME_BUFSIZE];
 	int dagstream;
 	int dagfd;
-	dag_card_inf_t *inf;
+	daginf_t *inf;
 	char *description;
 	int stream, rxstreams;
 
