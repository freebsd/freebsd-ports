--- ipacctctl/ipacctctl.c.orig	2006-02-07 19:55:24.406250000 +0300
+++ ipacctctl/ipacctctl.c	2006-02-07 20:13:25.734375000 +0300
@@ -36,6 +36,7 @@
 #include <sys/socket.h>
 #include <sys/queue.h>
 #include <sys/select.h>
+#include <inttypes.h>
 
 #include <net/bpf.h>        /* for DLT_XXX consts */
 #include <netinet/in.h>
@@ -56,6 +57,10 @@
 #define	IN_HOOK		0
 #define OUT_HOOK	1
 
+#ifndef PRIu64
+#define PRIu64	"qu"
+#endif
+
 int main(int, char **);
 
 static int ip_account_get_info(int _type, void *_buf, int _len, int _out);
@@ -459,7 +464,7 @@
 		    (hi->hi_thrs_when) ? stime : "Never");
 		printf("total number of packets:\t%u\n", 
 		    hi->hi_packets);
-		printf("total number of bytes:\t\t%qu\n", 
+		printf("total number of bytes:\t\t%" PRIu64 "\n", 
 		    hi->hi_bytes);
 		return;
 	}
@@ -473,9 +478,9 @@
 		    ng_hookprefix, (outgoing) ? "out" : "in");
 		printf("database type:\t\t%s\n",
 		    (type == NGM_IPACCT_CINFO) ? "checkpointed" : "active");
-		printf("accounted:\t\tpackets: %u\tbytes: %qu\n", 
+		printf("accounted:\t\tpackets: %u\tbytes: %" PRIu64 "\n", 
 		    ai->ai_packets, ai->ai_bytes);
-		printf("exceed threshold:\tpackets: %u\tbytes: %qu\n",
+		printf("exceed threshold:\tpackets: %u\tbytes: %" PRIu64 "\n",
 		    ai->ai_th_packets, ai->ai_th_bytes);
 		strftime(stime, sizeof(stime), TIME_FMT, localtime(&ai->ai_start));
 		printf("database was created:\t%s\n", 
@@ -642,7 +647,7 @@
 		ip_account_print(data, hi.hi_flags);
 	}
 	if (ci.ai_th_packets)
-		printf(" Accounting exceed threshold by %u packets (%qu bytes)\n",
+		printf(" Accounting exceed threshold by %u packets (%" PRIu64 " bytes)\n",
 		    ci.ai_th_packets, ci.ai_th_bytes);
 	
 	return (0);
@@ -707,12 +712,12 @@
 			inet_ntop(AF_INET, &pr->s.r_dst, dst, sizeof(dst));
 		}
 		if (flags & HI_VERBOSE_MODE) {
-			printf("%s\t%d\t%s\t%d\t%d\t%u\t%qu",
+			printf("%s\t%d\t%s\t%d\t%d\t%u\t%" PRIu64,
 			    src, ntohs(pr->s.r_sport), 
 			    dst, ntohs(pr->s.r_dport),
 			    pr->s.r_ip_p, pr->packets, pr->bytes);
 		} else {
-			printf("%s\t%s\t%u\t%qu",
+			printf("%s\t%s\t%u\t%" PRIu64,
 			    src, dst, pr->packets, pr->bytes);
 		}
 		if (flags & HI_SAVE_UID) {
