--- modules/dns/dns_ht.c.orig	Tue Aug  1 18:10:57 2006
+++ modules/dns/dns_ht.c	Tue Aug  1 18:11:07 2006
@@ -32,7 +32,11 @@
 #include <errno.h>
 
 #include "dns_ht.h"
-#include "resolv/resolv.h"
+
+#ifndef res_hostalias
+extern const char *_res_hostalias(const char *, char *, size_t);
+#define	res_hostalias(a, b, c, d)	_res_hostalias(b, c, d)
+#endif
 
 #define SPRINTF(x) ((size_t)sprintf x)
 
@@ -58,6 +62,7 @@
 	char ac;
 } align;
 
+#if 0
 pthread_key_t _res_key;
 pthread_key_t _res_ext_key;
 pthread_key_t _herrno_key;
@@ -99,15 +104,18 @@
 }
 
 extern void lookupd_res_send_init_keys();
+#endif
 
 void 
 _init()
 {
+#if 0
 	pthread_key_create(&_res_key, NULL);
 	pthread_key_create(&_res_ext_key, NULL);
 	pthread_key_create(&_herrno_key, NULL);
 
 	lookupd_res_send_init_keys();
+#endif
 }
 
 #ifdef DEBUG
@@ -168,10 +176,10 @@
 	switch (qtype) {
 	case T_A:
 	case T_AAAA:
-		name_ok = lookupd_res_hnok;
+		name_ok = res_hnok;
 		break;
 	case T_PTR:
-		name_ok = lookupd_res_dnok;
+		name_ok = res_dnok;
 		break;
 	default:
 		h_errno = NO_RECOVERY;
@@ -320,7 +328,7 @@
 				continue;	/* XXX - had_error++ ? */
 			}
 			n = dn_expand(answer->buf, eom, cp, bp, buflen);
-			if ((n < 0) || !lookupd_res_hnok(bp)) {
+			if ((n < 0) || !res_hnok(bp)) {
 				had_error++;
 				break;
 			}
@@ -473,8 +481,9 @@
 	char *bp;
 	int n, size, type, len;
 	struct hostent *hp;
+	char abuf[MAXDNAME];
 
-	if ((_res.options & RES_INIT) == 0 && lookupd_res_init() == -1) {
+	if ((_res.options & RES_INIT) == 0 && res_init() == -1) {
 		h_errno = NETDB_INTERNAL;
 		return (NULL);
 	}
@@ -499,7 +508,8 @@
 	/*
 	 * if there aren't any dots, it could be a user-level alias. this is also done in res_query() since we are not the only function that looks up host names.
 	 */
-	if (!strchr(name, '.') && (cp = lookupd_hostalias(name)))
+	if (!strchr(name, '.') &&
+	    (cp = res_hostalias(&_res, name, abuf, sizeof abuf)))
 		name = cp;
 
 	/*
@@ -572,7 +582,7 @@
 		h_errno = NETDB_INTERNAL;
 		return (NULL);
 	}
-	n = lookupd_res_search(name, C_IN, type, buf->buf, sizeof(buf->buf));
+	n = res_search(name, C_IN, type, buf->buf, sizeof(buf->buf));
 	if (n < 0) {
 		free(buf);
 		dprintf("res_search failed %s %d (%d)\n", name, type, n);
@@ -604,7 +614,7 @@
 	char hname2[MAXDNAME + 1];
 #endif				/* SUNSECURITY */
 
-	if ((_res.options & RES_INIT) == 0 && lookupd_res_init() == -1) {
+	if ((_res.options & RES_INIT) == 0 && res_init() == -1) {
 		h_errno = NETDB_INTERNAL;
 		return (NULL);
 	}
@@ -659,11 +669,11 @@
 		h_errno = NETDB_INTERNAL;
 		return (NULL);
 	}
-	n = lookupd_res_query(qbuf, C_IN, T_PTR, (u_char *) buf->buf, sizeof buf->buf);
+	n = res_query(qbuf, C_IN, T_PTR, (u_char *) buf->buf, sizeof buf->buf);
 	if (n < 0 && af == AF_INET6) {
 		*qp = '\0';
 		strlcat(qbuf, "ip6.int", sizeof(qbuf));
-		n = lookupd_res_query(qbuf, C_IN, T_PTR, (u_char *) buf->buf,
+		n = res_query(qbuf, C_IN, T_PTR, (u_char *) buf->buf,
 			sizeof buf->buf);
 	}
 	if (n < 0) {
