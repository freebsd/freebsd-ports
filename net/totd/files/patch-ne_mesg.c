diff -ru work/totd-1.3/ne_mesg.c work~/totd-1.3/ne_mesg.c
--- ne_mesg.c.orig	Wed Mar  6 06:56:02 2002
+++ ne_mesg.c	Sat Jun 14 22:17:24 2003
@@ -59,7 +59,7 @@
 
 	/* write qname */
 	if (T.debug > 4)
-		syslog (LOG_DEBUG, "%s: qname offset = %d", fn, ucp - buf);
+		syslog (LOG_DEBUG, "%s: qname offset = %d", fn, (int)(ucp - buf));
 
 	i = dname_copy (qname, ucp, buflen - written_len);
 	if (i < 0)
@@ -71,7 +71,7 @@
 	/* write qtype / qclass */
 	if (T.debug > 4)
 		syslog (LOG_DEBUG, "%s: qtype/qclass offset = %d",
-			fn, ucp - buf);
+			fn, (int)(ucp - buf));
 
 	written_len += sizeof (uint16_t) * 2;
 	if (written_len > buflen)
@@ -232,7 +232,7 @@
 	}
 
 	if (T.debug > 4)
-		syslog (LOG_DEBUG, "%s: return %d", fn, *wp - wp_start);
+		syslog (LOG_DEBUG, "%s: return %d", fn, (int)(*wp - wp_start));
 
 	return (*wp - wp_start);
 }
