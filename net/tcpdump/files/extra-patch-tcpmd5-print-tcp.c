--- print-tcp.c.orig	Mon Aug  2 18:47:22 2004
+++ print-tcp.c	Mon Aug  2 18:47:30 2004
@@ -50,6 +50,13 @@
 
 #include "nameser.h"
 
+#ifdef HAVE_LIBCRYPTO
+#include <openssl/md5.h>
+
+static int tcp_verify_signature(const struct ip *ip, const struct tcphdr *tp,
+    const u_char *data, int length, const u_char *rcvsig);
+#endif
+
 static void print_tcp_rst_data(register const u_char *sp, u_int length);
 
 #define MAX_RST_DATA_LEN	30
@@ -561,6 +568,22 @@
 				(void)printf(" %u", EXTRACT_32BITS(cp));
 				break;
 
+			case TCPOPT_SIGNATURE:
+				(void)printf("md5:");
+				datalen = TCP_SIGLEN;
+				LENCHECK(datalen);
+#ifdef HAVE_LIBCRYPTO
+				if (tcp_verify_signature(ip, tp,
+				    bp + TH_OFF(tp) * 4, length, cp) == 0)
+					(void)printf("valid");
+				else
+					(void)printf("invalid");
+#else
+				for (i = 0; i < TCP_SIGLEN; ++i)
+					(void)printf("%02x", cp[i]);
+#endif
+				break;
+
 			default:
 				(void)printf("opt-%u:", opt);
 				datalen = len - 2;
@@ -673,3 +696,72 @@
 	}
 	putchar(']');
 }
+
+#ifdef HAVE_LIBCRYPTO
+static int
+tcp_verify_signature(const struct ip *ip, const struct tcphdr *tp,
+    const u_char *data, int length, const u_char *rcvsig)
+{
+        struct tcphdr tp1;
+	char sig[TCP_SIGLEN];
+	char zero_proto = 0;
+	MD5_CTX ctx;
+	u_int16_t savecsum, tlen;
+	struct ip6_hdr *ip6;
+	u_int32_t len32;
+	u_int8_t nxt;
+
+	tp1 = *tp;
+
+	if (tcpmd5secret == NULL)
+		return (-1);
+
+	MD5_Init(&ctx);
+	/*
+	 * Step 1: Update MD5 hash with IP pseudo-header.
+	 */
+	if (IP_V(ip) == 4) {
+		MD5_Update(&ctx, (char *)&ip->ip_src, sizeof(ip->ip_src));
+		MD5_Update(&ctx, (char *)&ip->ip_dst, sizeof(ip->ip_dst));
+		MD5_Update(&ctx, (char *)&zero_proto, sizeof(zero_proto));
+		MD5_Update(&ctx, (char *)&ip->ip_p, sizeof(ip->ip_p));
+		tlen = EXTRACT_16BITS(&ip->ip_len) - IP_HL(ip) * 4;
+		tlen = htons(tlen);
+		MD5_Update(&ctx, (char *)&tlen, sizeof(tlen));
+	} else if (IP_V(ip) == 6) {
+		ip6 = (struct ip6_hdr *)ip;
+		MD5_Update(&ctx, (char *)&ip6->ip6_src, sizeof(ip6->ip6_src));
+		MD5_Update(&ctx, (char *)&ip6->ip6_dst, sizeof(ip6->ip6_dst));
+		len32 = htonl(ntohs(ip6->ip6_plen));
+		MD5_Update(&ctx, (char *)&len32, sizeof(len32));
+		nxt = 0;
+		MD5_Update(&ctx, (char *)&nxt, sizeof(nxt));
+		MD5_Update(&ctx, (char *)&nxt, sizeof(nxt));
+		MD5_Update(&ctx, (char *)&nxt, sizeof(nxt));
+		nxt = IPPROTO_TCP;
+		MD5_Update(&ctx, (char *)&nxt, sizeof(nxt));
+	} else
+		return (-1);
+
+	/*
+	 * Step 2: Update MD5 hash with TCP header, excluding options.
+	 * The TCP checksum must be set to zero.
+	 */
+	savecsum = tp1.th_sum;
+	tp1.th_sum = 0;
+	MD5_Update(&ctx, (char *)&tp1, sizeof(struct tcphdr));
+	tp1.th_sum = savecsum;
+	/*
+	 * Step 3: Update MD5 hash with TCP segment data, if present.
+	 */
+	if (length > 0)
+		MD5_Update(&ctx, data, length);
+	/*
+	 * Step 4: Update MD5 hash with shared secret.
+	 */
+	MD5_Update(&ctx, tcpmd5secret, strlen(tcpmd5secret));
+	MD5_Final(sig, &ctx);
+
+	return (memcmp(rcvsig, sig, 16));
+}
+#endif /* HAVE_LIBCRYPTO */
