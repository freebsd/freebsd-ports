--- ./spamd-setup/spamd-setup.c.orig	2009-07-19 19:11:35.000000000 +0200
+++ ./spamd-setup/spamd-setup.c	2009-10-31 10:58:24.000000000 +0100
@@ -83,7 +83,7 @@
 u_int8_t	  maxdiff(u_int32_t, u_int32_t);
 struct cidr	 *range2cidrlist(u_int32_t, u_int32_t);
 void		  cidr2range(struct cidr, u_int32_t *, u_int32_t *);
-char		 *atop(u_int32_t);
+char		 *a_to_p(u_int32_t);
 int		  parse_netblock(char *, struct bl *, struct bl *, int);
 int		  open_child(char *, char **);
 int		  fileget(char *);
@@ -187,8 +187,10 @@
 	*end = cidr.addr + (1 << (32 - cidr.bits)) - 1;
 }
 
+/* rename atop to a_to_p, since
+ * it collides at FreeBSD9 with atop in machine/param.h */
 char *
-atop(u_int32_t addr)
+a_to_p(u_int32_t addr)
 {
 	struct in_addr in;
 
@@ -621,7 +623,7 @@
 	while (*blacklists != NULL) {
 		struct cidr *b = *blacklists;
 		while (b->addr != 0) {
-			fprintf(sdc, ";%s/%u", atop(b->addr), (b->bits));
+			fprintf(sdc, ";%s/%u", a_to_p(b->addr), (b->bits));
 			b++;
 		}
 		blacklists++;
@@ -672,7 +674,7 @@
 		struct cidr *b = *blacklists;
 
 		while (b->addr != 0) {
-			fprintf(pf, "%s/%u\n", atop(b->addr), (b->bits));
+			fprintf(pf, "%s/%u\n", a_to_p(b->addr), (b->bits));
 			b++;
 		}
 		blacklists++;
@@ -711,7 +713,7 @@
 			ent.tbl = ipfw_tabno;
 			ent.masklen = b->bits;
 			ent.value = 0;
-			inet_aton(atop(b->addr), (struct in_addr *)&ent.addr);
+			inet_aton(a_to_p(b->addr), (struct in_addr *)&ent.addr);
 			if (setsockopt(s, IPPROTO_IP, IP_FW_TABLE_ADD,  &ent, sizeof(ent)) < 0)
 			{
 				err(1, "IPFW setsockopt(IP_FW_TABLE_ADD)");
