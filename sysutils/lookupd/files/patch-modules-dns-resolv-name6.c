--- modules/dns/resolv/name6.c.orig	Tue Aug  1 18:10:57 2006
+++ modules/dns/resolv/name6.c	Tue Aug  1 18:11:07 2006
@@ -40,6 +40,7 @@
 #include <arpa/nameser.h>
 
 #include <errno.h>
+#include <resolv.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -54,7 +55,6 @@
 #include "namespace.h"
 #include "un-namespace.h"
 #include "../dns_ht.h"
-#include "resolv.h"
 
 
 #ifndef _PATH_HOSTS
@@ -103,6 +103,11 @@
 #define	map_inaddr	map_addr_un.mau_inaddr
 };
 
+#ifndef res_hostalias
+extern const char *_res_hostalias(const char *, char *, size_t);
+#define	res_hostalias(a, b, c, d)	_res_hostalias(b, c, d)
+#endif
+
 static struct hostent *_hpcopy(struct hostent * hp);
 static struct hostent *_hpmerge(struct hostent * hp1, struct hostent * hp2);
 #ifdef INET6
@@ -284,7 +289,7 @@
 	hp6->h_addrtype = AF_INET6;
 	hp6->h_length = sizeof(struct in6_addr);
 	hp6->h_addr_list = NULL;
-	return _hpmerge(hp6, hp, errp);
+	return _hpmerge(hp6, hp);
 }
 #endif
 
@@ -358,10 +363,10 @@
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
 		return (NULL);	/* XXX should be abort(); */
@@ -450,7 +455,7 @@
 		}
 		if (qtype == T_PTR && type == T_CNAME) {
 			n = dn_expand(answer->buf, eom, cp, tbuf, sizeof tbuf);
-			if (n < 0 || !lookupd_res_dnok(tbuf)) {
+			if (n < 0 || !res_dnok(tbuf)) {
 				had_error++;
 				continue;
 			}
@@ -476,7 +481,7 @@
 			DNS_ASSERT(strcasecmp(tname, bp) == 0);
 			n = dn_expand(answer->buf, eom, cp, bp, ep - bp);
 			DNS_FATAL(n >= 0);
-			DNS_FATAL(lookupd_res_hnok(bp));
+			DNS_FATAL(res_hnok(bp));
 #if MULTI_PTRS_ARE_ALIASES
 			cp += n;
 			if (cp != erdata) {
@@ -574,6 +579,7 @@
 	int got_nodata = 0, got_servfail = 0, tried_as_is = 0;
 	struct __res_type_list *rtl0 = rtl;
 	querybuf *buf;
+	char abuf[MAXDNAME];
 
 	if ((_res.options & RES_INIT) == 0 && res_init() == -1) {
 		h_errno = NETDB_INTERNAL;
@@ -592,7 +598,8 @@
 		return NULL;
 	}
 	/* If there aren't any dots, it could be a user-level alias */
-	if (!dots && (cp = lookupd_hostalias(name)) != NULL) {
+	if (!dots &&
+	    (cp = res_hostalias(&_res, name, abuf, sizeof(abuf))) != NULL) {
 		for (rtl = rtl0; rtl != NULL;
 			rtl = SLIST_NEXT(rtl, rtl_entry)) {
 			ret = res_query(cp, C_IN, rtl->rtl_type, buf->buf,
@@ -866,7 +873,7 @@
 			break;
 		}
 
-		n = lookupd_res_query(qbuf, C_IN, T_PTR, buf->buf, sizeof buf->buf);
+		n = res_query(qbuf, C_IN, T_PTR, buf->buf, sizeof buf->buf);
 		if (n < 0) {
 			err = NS_UNAVAIL;
 			continue;
