Index: src/libspf2/spf_expand.c
diff -u -p src/libspf2/spf_expand.c.orig src/libspf2/spf_expand.c
--- src/libspf2/spf_expand.c.orig	2008-11-04 06:29:00.000000000 +0900
+++ src/libspf2/spf_expand.c	2009-11-02 01:50:13.008764120 +0900
@@ -245,7 +245,7 @@ top:
 		case PARM_CLIENT_IP:		/* SMTP client IP				*/
 #ifdef COMPUTE
 			if (compute_length) {
-				len = sizeof(ip6_buf);
+				len = sizeof(ip6_rbuf);
 				if (d->dv.url_encode)
 					len *= 3;
 				buflen += len;
