--- portinuse.c.orig	2017-11-02 17:38:02 UTC
+++ portinuse.c
@@ -280,7 +280,7 @@ static struct nlist list[] = {
 	struct xinpgen *xig, *exig;
 	struct xinpcb *xip;
 	struct xtcpcb *xtp;
-	struct inpcb *inp;
+	struct in_conninfo *inc;
 	void *buf = NULL;
 	size_t len;
 
@@ -339,7 +339,8 @@ static struct nlist list[] = {
 				free(buf);
 				return -1;
 			}
-			inp = &xtp->xt_inp;
+			xip = &xtp->xt_inp;
+			inc = &xip->inp_inc;
 			break;
 		case IPPROTO_UDP:
 			xip = (struct xinpcb *)xig;
@@ -349,21 +350,21 @@ static struct nlist list[] = {
 				free(buf);
 				return -1;
 			}
-			inp = &xip->xi_inp;
+			inc = &xip->inp_inc;
 			break;
 		default:
 			abort();
 		}
 		/* no support for IPv6 */
-		if ((inp->inp_vflag & INP_IPV6) != 0)
+		if ((xip->inp_vflag & INP_IPV6) != 0)
 			continue;
 		syslog(LOG_DEBUG, "%08lx:%hu %08lx:%hu <=> %hu %08lx:%hu",
-		       (u_long)inp->inp_laddr.s_addr, ntohs(inp->inp_lport),
-		       (u_long)inp->inp_faddr.s_addr, ntohs(inp->inp_fport),
+		       (u_long)inc->inc_laddr.s_addr, ntohs(inc->inc_lport),
+		       (u_long)inc->inc_faddr.s_addr, ntohs(inc->inc_fport),
 		       eport, (u_long)ip_addr.s_addr, iport
 		);
-		if (eport == (unsigned)ntohs(inp->inp_lport)) {
-			if (inp->inp_laddr.s_addr == INADDR_ANY || inp->inp_laddr.s_addr == ip_addr.s_addr) {
+		if (eport == (unsigned)ntohs(inc->inc_lport)) {
+			if (inc->inc_laddr.s_addr == INADDR_ANY || inc->inc_laddr.s_addr == ip_addr.s_addr) {
 				found++;
 				break;  /* don't care how many, just that we found at least one */
 			}
