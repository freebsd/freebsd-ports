--- module/trafcount.c.orig	Mon Dec 24 15:34:22 2001
+++ module/trafcount.c	Mon Dec 24 15:34:55 2001
@@ -37,7 +37,7 @@
 static ip_fw_chk_t *trafcount_old_chk_ptr;
 static int	trafcount_ip_fw_chk __P((struct ip **pip, int hlen,
 			struct ifnet *oif, u_int16_t *cookie, struct mbuf **m,
-			struct ip_fw_chain **flow_id,
+			struct ip_fw **flow_id,
 			struct sockaddr_in **next_hop));
 
 LIST_HEAD(rulechain_head, rulechain) trafcount_rulechain; /* defines the rule list */
@@ -86,7 +86,7 @@
 static int
 trafcount_ip_fw_chk(struct ip **pip, int hlen,
 	struct ifnet *oif, u_int16_t *cookie, struct mbuf **m,
-	struct ip_fw_chain **flow_id,
+	struct ip_fw **flow_id,
         struct sockaddr_in **next_hop)
 {
 	struct ip *ip = *pip;
