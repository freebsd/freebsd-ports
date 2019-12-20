diff --git a/nametoaddr.c b/nametoaddr.c
index 53070a28..13bf4c68 100644
--- nametoaddr.c
+++ nametoaddr.c
@@ -674,8 +674,15 @@ __pcap_atoin(const char *s, bpf_u_int32 *addr)
 	len = 0;
 	for (;;) {
 		n = 0;
-		while (*s && *s != '.')
+		while (*s && *s != '.') {
+			if (n > 25) {
+				/* The result will be > 255 */
+				return -1;
+			}
 			n = n * 10 + *s++ - '0';
+		}
+		if (n > 255)
+			return -1;
 		*addr <<= 8;
 		*addr |= n & 0xff;
 		len += 8;
