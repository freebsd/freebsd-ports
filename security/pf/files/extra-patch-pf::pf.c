Update pf to be more in line with current TCP stack behaviour at
5.2 code freeze point after andre's initial commit to decouple
protocol-level stats from routing. --  bms@FreeBSD.org

--- pf/pf.c.orig	Wed Nov 19 11:51:34 2003
+++ pf/pf.c	Wed Nov 19 11:53:42 2003
@@ -1376,14 +1376,10 @@
 		 */
 		NTOHS(ip->ip_len);
 		NTOHS(ip->ip_off);
-		ip_rtaddr(ip->ip_dst, &ro);
 		PF_UNLOCK();
-		ip_output(m, (void *)NULL, &ro, 0, (void *)NULL,
+		ip_output(m, (void *)NULL, (void *)NULL, 0, (void *)NULL,
 			(void *)NULL);
 		PF_LOCK();
-		if(ro.ro_rt) {
-			RTFREE(ro.ro_rt);
-		}
 #else
 		ip_output(m, (void *)NULL, (void *)NULL, 0, (void *)NULL,
 		    (void *)NULL);
