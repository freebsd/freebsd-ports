--- trafshow.c.orig	2023-06-13 16:53:56.932059000 +0700
+++ trafshow.c	2023-06-13 16:57:12.824618000 +0700
@@ -20,6 +20,7 @@
 #endif
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/ioctl.h>
 #ifdef	HAVE_PCAP_GET_SELECTABLE_FD
 #include <sys/select.h>
 #endif
@@ -59,7 +60,7 @@ static pcap_if_t *pcap_matchdev(pcap_if_t *dp, const c
 static void vers();
 static void usage();
 static pcap_if_t *pcap_matchdev(pcap_if_t *dp, const char *name);
-static int pcap_init(PCAP_HANDLER **ph_list, pcap_if_t *dp);
+static int ts_pcap_init(PCAP_HANDLER **ph_list, pcap_if_t *dp);
 static void *pcap_feed(void *arg); /* PCAP_HANDLER *ph */
 #ifdef	HAVE_PCAP_GET_SELECTABLE_FD
 static void *pcap_feed2(void *arg); /* PCAP_HANDLER *ph */
@@ -173,7 +174,7 @@ main(argc, argv)
 	}
 
 	/* initialize list of pcap handlers */
-	if ((op = pcap_init(&ph_list, dev_list)) < 1) {
+	if ((op = ts_pcap_init(&ph_list, dev_list)) < 1) {
 		fprintf(stderr, "No packet capture device available (no permission?)\n");
 		exit(1);
 	}
@@ -299,7 +300,7 @@ static int
 }
 
 static int
-pcap_init(ph_list, dp)
+ts_pcap_init(ph_list, dp)
 	PCAP_HANDLER **ph_list;
 	pcap_if_t *dp;
 {
@@ -308,6 +309,7 @@ pcap_init(ph_list, dp)
 	const pcap_addr_t *ap;
 	PCAP_HANDLER *ph, *ph_prev = 0;
 	char *cp, buf[256];
+	int v = 1;
 
 	if (!ph_list) return -1;
 
@@ -339,6 +341,12 @@ pcap_init(ph_list, dp)
 			err++;
 			continue;
 		}
+		if (ioctl(pcap_fileno(pd), BIOCIMMEDIATE, &v) < 0) {
+			fprintf(stderr, "%s: %s\n", dp->name, strerror(errno));
+			pcap_close(pd);
+			err++;
+			continue;
+		}
 		if ((ph = (PCAP_HANDLER *)malloc(sizeof(PCAP_HANDLER))) == 0) {
 			perror("malloc");
 			exit(1);
