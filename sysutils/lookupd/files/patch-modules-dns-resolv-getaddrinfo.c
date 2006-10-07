--- modules/dns/resolv/getaddrinfo.c.orig	Tue Aug  1 18:10:57 2006
+++ modules/dns/resolv/getaddrinfo.c	Tue Aug  1 18:11:07 2006
@@ -1,46 +1,77 @@
-/* $KAME: getaddrinfo.c,v 1.15 2000/07/09 04:37:24 itojun Exp $	 */
-/* Copyright (c) 2004 Michael Bushkov <bushman@rsu.ru> */
+/*	$KAME: getaddrinfo.c,v 1.15 2000/07/09 04:37:24 itojun Exp $	*/
+
 /*
- * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project. All rights reserved.
- * 
- * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met: 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. 3. Neither the name of the project nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
- * 
- * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the project nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
  */
 
 /*
  * "#ifdef FAITH" part is local hack for supporting IPv4-v6 translator.
- * 
- * Issues to be discussed: - Thread safe-ness must be checked. - Return values.  There are nonstandard return values defined and used in the source code.  This is because RFC2553 is silent about which error code must be returned for which situation. - freeaddrinfo(NULL).  RFC2553 is silent about it.  XNET 5.2 says it is invalid.  current code - SEGV on freeaddrinfo(NULL)
- * 
- * Note: - The code filters out AFs that are not supported by the kernel, when globbing NULL hostname (to loopback, or wildcard).  Is it the right thing to do?  What is the relationship with post-RFC2553 AI_ADDRCONFIG in ai_flags? - (post-2553) semantics of AI_ADDRCONFIG itself is too vague. (1) what should we do against numeric hostname (2) what should we do against NULL hostname (3) what is AI_ADDRCONFIG itself.  AF not ready? non-loopback address configured?  global address configured?
- * 
- * OS specific notes for netbsd/openbsd/freebsd4/bsdi4: - To avoid search order issue, we have a big amount of code duplicate from gethnamaddr.c and some other places.  The issues that there's no lower layer function to lookup "IPv4 or IPv6" record.  Calling gethostbyname2 from getaddrinfo will end up in wrong search order, as presented above.
- * 
- * OS specific notes for freebsd4: - FreeBSD supported $GAI.  The code does not. - FreeBSD allowed classful IPv4 numeric (127.1), the code does not.
+ *
+ * Issues to be discussed:
+ * - Thread safe-ness must be checked.
+ * - Return values.  There are nonstandard return values defined and used
+ *   in the source code.  This is because RFC2553 is silent about which error
+ *   code must be returned for which situation.
+ * - freeaddrinfo(NULL).  RFC2553 is silent about it.  XNET 5.2 says it is
+ *   invalid.  current code - SEGV on freeaddrinfo(NULL)
+ *
+ * Note:
+ * - The code filters out AFs that are not supported by the kernel,
+ *   when globbing NULL hostname (to loopback, or wildcard).  Is it the right
+ *   thing to do?  What is the relationship with post-RFC2553 AI_ADDRCONFIG
+ *   in ai_flags?
+ * - (post-2553) semantics of AI_ADDRCONFIG itself is too vague.
+ *   (1) what should we do against numeric hostname (2) what should we do
+ *   against NULL hostname (3) what is AI_ADDRCONFIG itself.  AF not ready?
+ *   non-loopback address configured?  global address configured?
+ *
+ * OS specific notes for netbsd/openbsd/freebsd4/bsdi4:
+ * - To avoid search order issue, we have a big amount of code duplicate
+ *   from gethnamaddr.c and some other places.  The issues that there's no
+ *   lower layer function to lookup "IPv4 or IPv6" record.  Calling
+ *   gethostbyname2 from getaddrinfo will end up in wrong search order, as
+ *   presented above.
+ *
+ * OS specific notes for freebsd4:
+ * - FreeBSD supported $GAI.  The code does not.
+ * - FreeBSD allowed classful IPv4 numeric (127.1), the code does not.
  */
 
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD: src/lib/libc/net/getaddrinfo.c,v 1.49 2004/02/25 21:03:45 green Exp $");
+__FBSDID("$FreeBSD: src/lib/libc/net/getaddrinfo.c,v 1.49 2004/02/25 21:03:45 green Exp $");
 
 #include <sys/types.h>
 #include <sys/param.h>
-#include <sys/socket.h>
-#include <net/if.h>
 #include <netinet/in.h>
-#include <sys/queue.h>
-#ifdef INET6
-#include <net/if_var.h>
-#include <sys/sysctl.h>
-#include <netinet6/in6_var.h>	/* XXX */
-#endif
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
-#include <rpc/rpc.h>
-#include <rpcsvc/yp_prot.h>
-#include <rpcsvc/ypclnt.h>
 #include <netdb.h>
-#include <pthread.h>
+#include <resolv.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stddef.h>
@@ -48,1117 +79,140 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <errno.h>
-#include <stdarg.h>
-#include <nsswitch.h>
-
-#include "un-namespace.h"
-#include "namespace.h"
-#include "res_config.h"
-#include "resolv.h"
-
-#if defined(__KAME__) && defined(INET6)
-#define FAITH
-#endif
-
-#define SUCCESS 0
-#define ANY 0
-#define YES 1
-#define NO  0
-
-#ifdef DEBUG
-#include <syslog.h>
-#endif
-
-static const char in_addrany[] = {0, 0, 0, 0};
-static const char in_loopback[] = {127, 0, 0, 1};
-#ifdef INET6
-static const char in6_addrany[] = {
-	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
-};
-static const char in6_loopback[] = {
-	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
-};
-#endif
-
-struct policyqueue {
-	TAILQ_ENTRY(policyqueue) pc_entry;
-#ifdef INET6
-	struct in6_addrpolicy pc_policy;
-#endif
-};
-TAILQ_HEAD(policyhead, policyqueue);
-
-static const struct afd {
-	int a_af;
-	int a_addrlen;
-	int a_socklen;
-	int a_off;
-	 const char *a_addrany;
-	 const char *a_loopback;
-	int a_scoped;
-} afdl[] = {
-#ifdef INET6
-#define	N_INET6 0
-	{
-		PF_INET6, sizeof(struct in6_addr),
-		sizeof(struct sockaddr_in6),
-		offsetof(struct sockaddr_in6, sin6_addr),
-		in6_addrany, in6_loopback, 1
-	},
-#define	N_INET 1
-#else
-#define	N_INET 0
-#endif
-	{
-		PF_INET, sizeof(struct in_addr),
-		sizeof(struct sockaddr_in),
-		offsetof(struct sockaddr_in, sin_addr),
-		in_addrany, in_loopback, 0
-	},
-	{
-		0, 0, 0, 0, NULL, NULL, 0
-	},
-};
-
-struct explore {
-	int e_af;
-	int e_socktype;
-	int e_protocol;
-	 const char *e_protostr;
-	int e_wild;
-#define WILD_AF(ex)		((ex)->e_wild & 0x01)
-#define WILD_SOCKTYPE(ex)	((ex)->e_wild & 0x02)
-#define WILD_PROTOCOL(ex)	((ex)->e_wild & 0x04)
-};
-
-static const struct explore explore[] = {
-#if 0
-	{PF_LOCAL, 0, ANY, ANY, NULL, 0x01},
-#endif
-#ifdef INET6
-	{PF_INET6, SOCK_DGRAM, IPPROTO_UDP, "udp", 0x07},
-	{PF_INET6, SOCK_STREAM, IPPROTO_TCP, "tcp", 0x07},
-	{PF_INET6, SOCK_RAW, ANY, NULL, 0x05},
-#endif
-	{PF_INET, SOCK_DGRAM, IPPROTO_UDP, "udp", 0x07},
-	{PF_INET, SOCK_STREAM, IPPROTO_TCP, "tcp", 0x07},
-	{PF_INET, SOCK_RAW, ANY, NULL, 0x05},
-	{PF_UNSPEC, SOCK_DGRAM, IPPROTO_UDP, "udp", 0x07},
-	{PF_UNSPEC, SOCK_STREAM, IPPROTO_TCP, "tcp", 0x07},
-	{PF_UNSPEC, SOCK_RAW, ANY, NULL, 0x05},
-	{-1, 0, 0, NULL, 0},
-};
-
-#ifdef INET6
-#define PTON_MAX	16
-#else
-#define PTON_MAX	4
-#endif
-
-#define AIO_SRCFLAG_DEPRECATED	0x1
-
-struct ai_order {
-	union {
-		struct sockaddr_storage aiou_ss;
-		struct sockaddr aiou_sa;
-	} aio_src_un;
-#define aio_srcsa aio_src_un.aiou_sa
-	u_int32_t aio_srcflag;
-	int aio_srcscope;
-	int aio_dstscope;
-	struct policyqueue *aio_srcpolicy;
-	struct policyqueue *aio_dstpolicy;
-	struct addrinfo *aio_ai;
-	int aio_matchlen;
-};
-
-struct res_target {
-	struct res_target *next;
-	 const char *name;	/* domain name */
-	int qclass, qtype;	/* class and type of query */
-	u_char *answer;		/* buffer to put answer */
-	int anslen;		/* size of answer buffer */
-	int n;			/* result length */
-};
-
-#define MAXPACKET	(64*1024)
-
-typedef union {
-	HEADER hdr;
-	u_char buf[MAXPACKET];
-} querybuf;
-
-static int str_isnumber(const char *);
-static int 
-explore_null(const struct addrinfo *,
-	const char *, struct addrinfo **);
-static int 
-explore_numeric(const struct addrinfo *, const char *,
-	const char *, struct addrinfo **);
-static int 
-explore_numeric_scope(const struct addrinfo *, const char *,
-	const char *, struct addrinfo **);
-static int 
-get_canonname(const struct addrinfo *,
-	struct addrinfo *, const char *);
-static struct addrinfo *
-get_ai(const struct addrinfo *,
-	const struct afd *, const char *);
-static int get_portmatch(const struct addrinfo *, const char *);
-static int get_port(struct addrinfo *, const char *, int);
-static const struct afd *find_afd(int);
-static int addrconfig(struct addrinfo *);
-static int comp_dst(const void *, const void *);
-#ifdef INET6
-static int ip6_str2scopeid(char *, struct sockaddr_in6 *, u_int32_t *);
-#endif
-static int gai_addr2scopetype(struct sockaddr *);
-
-static int 
-explore_fqdn(const struct addrinfo *, const char *,
-	const char *, struct addrinfo **);
-
-static int reorder(struct addrinfo *);
-static int get_addrselectpolicy(struct policyhead *);
-static void free_addrselectpolicy(struct policyhead *);
-static struct policyqueue *
-match_addrselectpolicy(struct sockaddr *,
-	struct policyhead *);
-
-static struct addrinfo *
-getanswer(const querybuf *, int, const char *, int,
-	const struct addrinfo *);
-#if defined(RESOLVSORT)
-static int addr4sort(struct addrinfo *);
-#endif
-int lookupd_dns_getaddrinfo(void *, const char *, const struct addrinfo *);
-
-static int res_queryN(const char *, struct res_target *);
-static int res_searchN(const char *, struct res_target *);
-static int 
-res_querydomainN(const char *, const char *,
-	struct res_target *);
-
-static struct ai_errlist {
-	const char *str;
-	int code;
-} ai_errlist[] = {
-	{
-		"Success", 0,
-	},
-	{
-		"Temporary failure in name resolution", EAI_AGAIN,
-	},
-	{
-		"Invalid value for ai_flags", EAI_BADFLAGS,
-	},
-	{
-		"Non-recoverable failure in name resolution", EAI_FAIL,
-	},
-	{
-		"ai_family not supported", EAI_FAMILY,
-	},
-	{
-		"Memory allocation failure", EAI_MEMORY,
-	},
-	{
-		"hostname nor servname provided, or not known", EAI_NONAME,
-	},
-	{
-		"servname not supported for ai_socktype", EAI_SERVICE,
-	},
-	{
-		"ai_socktype not supported", EAI_SOCKTYPE,
-	},
-	{
-		"System error returned in errno", EAI_SYSTEM,
-	},
-	{
-		"Invalid value for hints", EAI_BADHINTS,
-	},
-	{
-		"Resolved protocol is unknown", EAI_PROTOCOL,
-	},
-	/* backward compatibility with userland code prior to 2553bis-02 */
-	{
-		"Address family for hostname not supported", 1,
-	},
-	{
-		"No address associated with hostname", 7,
-	},
-	{
-		NULL, -1,
-	},
-};
-
-/*
- * XXX: Many dependencies are not thread-safe.  So, we share lock between getaddrinfo() and getipnodeby*().  Still, we cannot use getaddrinfo() and getipnodeby*() in conjunction with other functions which call them.
- */
-pthread_mutex_t __getaddrinfo_thread_lock = PTHREAD_MUTEX_INITIALIZER;
-#define THREAD_LOCK() pthread_mutex_lock(&__getaddrinfo_thread_lock);
-#define THREAD_UNLOCK() pthread_mutex_unlock(&__getaddrinfo_thread_lock);
-
-/* XXX macros that make external reference is BAD. */
-
-#define GET_AI(ai, afd, addr) \
-do { \
-	/* external reference: pai, error, and label free */ \
-	(ai) = get_ai(pai, (afd), (addr)); \
-	if ((ai) == NULL) { \
-		error = EAI_MEMORY; \
-		goto free; \
-	} \
-} while (/*CONSTCOND*/0)
-
-#define GET_PORT(ai, serv) \
-do { \
-	/* external reference: error and label free */ \
-	error = get_port((ai), (serv), 0); \
-	if (error != 0) \
-		goto free; \
-} while (/*CONSTCOND*/0)
-
-#define GET_CANONNAME(ai, str) \
-do { \
-	/* external reference: pai, error and label free */ \
-	error = get_canonname(pai, (ai), (str)); \
-	if (error != 0) \
-		goto free; \
-} while (/*CONSTCOND*/0)
-
-#define ERR(err) \
-do { \
-	/* external reference: error, and label bad */ \
-	error = (err); \
-	goto bad; \
-	/*NOTREACHED*/ \
-} while (/*CONSTCOND*/0)
-
-#define MATCH_FAMILY(x, y, w) \
-	((x) == (y) || (/*CONSTCOND*/(w) && ((x) == PF_UNSPEC || (y) == PF_UNSPEC)))
-#define MATCH(x, y, w) \
-	((x) == (y) || (/*CONSTCOND*/(w) && ((x) == ANY || (y) == ANY)))
-
-char *
-gai_strerror(ecode)
-	int ecode;
-{
-	struct ai_errlist *p;
-
-	for (p = ai_errlist; p->str; p++) {
-		if (p->code == ecode)
-			return (char *)p->str;
-	}
-	return "Unknown error";
-}
-
-void
-freeaddrinfo(ai)
-	struct addrinfo *ai;
-{
-	struct addrinfo *next;
-
-	do {
-		next = ai->ai_next;
-		if (ai->ai_canonname)
-			free(ai->ai_canonname);
-		/* no need to free(ai->ai_addr) */
-		free(ai);
-		ai = next;
-	} while (ai);
-}
-
-static int
-str_isnumber(p)
-	const char *p;
-{
-	char *ep;
-
-	if (*p == '\0')
-		return NO;
-	ep = NULL;
-	errno = 0;
-	(void)strtoul(p, &ep, 10);
-	if (errno == 0 && ep && *ep == '\0')
-		return YES;
-	else
-		return NO;
-}
-
-int
-lookupd_getaddrinfo(hostname, servname, hints, res)
-	const char *hostname, *servname;
-	const struct addrinfo *hints;
-	struct addrinfo **res;
-{
-	struct addrinfo sentinel;
-	struct addrinfo *cur;
-	int error = 0;
-	struct addrinfo ai;
-	struct addrinfo ai0;
-	struct addrinfo *pai;
-	const struct explore *ex;
-	int numeric = 0;
-
-	memset(&sentinel, 0, sizeof(sentinel));
-	cur = &sentinel;
-	pai = &ai;
-	pai->ai_flags = 0;
-	pai->ai_family = PF_UNSPEC;
-	pai->ai_socktype = ANY;
-	pai->ai_protocol = ANY;
-	pai->ai_addrlen = 0;
-	pai->ai_canonname = NULL;
-	pai->ai_addr = NULL;
-	pai->ai_next = NULL;
-
-	if (hostname == NULL && servname == NULL)
-		return EAI_NONAME;
-	if (hints) {
-		/* error check for hints */
-		if (hints->ai_addrlen || hints->ai_canonname ||
-			hints->ai_addr || hints->ai_next)
-			ERR(EAI_BADHINTS);	/* xxx */
-		if (hints->ai_flags & ~AI_MASK)
-			ERR(EAI_BADFLAGS);
-		switch (hints->ai_family) {
-		case PF_UNSPEC:
-		case PF_INET:
-#ifdef INET6
-		case PF_INET6:
-#endif
-			break;
-		default:
-			ERR(EAI_FAMILY);
-		}
-		memcpy(pai, hints, sizeof(*pai));
-
-		/*
-		 * if both socktype/protocol are specified, check if they are meaningful combination.
-		 */
-		if (pai->ai_socktype != ANY && pai->ai_protocol != ANY) {
-			for (ex = explore; ex->e_af >= 0; ex++) {
-				if (pai->ai_family != ex->e_af)
-					continue;
-				if (ex->e_socktype == ANY)
-					continue;
-				if (ex->e_protocol == ANY)
-					continue;
-				if (pai->ai_socktype == ex->e_socktype &&
-					pai->ai_protocol != ex->e_protocol) {
-					ERR(EAI_BADHINTS);
-				}
-			}
-		}
-	}
-	/*
-	 * post-2553: AI_ALL and AI_V4MAPPED are effective only against AF_INET6 query.  They need to be ignored if specified in other occassions.
-	 */
-	switch (pai->ai_flags & (AI_ALL | AI_V4MAPPED)) {
-	case AI_V4MAPPED:
-	case AI_ALL | AI_V4MAPPED:
-		if (pai->ai_family != AF_INET6)
-			pai->ai_flags &= ~(AI_ALL | AI_V4MAPPED);
-		break;
-	case AI_ALL:
-#if 1
-		/* illegal */
-		ERR(EAI_BADFLAGS);
-#else
-		pai->ai_flags &= ~(AI_ALL | AI_V4MAPPED);
-#endif
-		break;
-	}
-
-	/*
-	 * check for special cases.  (1) numeric servname is disallowed if socktype/protocol are left unspecified. (2) servname is disallowed for raw and other inet{,6} sockets.
-	 */
-	if (MATCH_FAMILY(pai->ai_family, PF_INET, 1)
-#ifdef PF_INET6
-		|| MATCH_FAMILY(pai->ai_family, PF_INET6, 1)
-#endif
-		) {
-		ai0 = *pai;	/* backup *pai */
-
-		if (pai->ai_family == PF_UNSPEC) {
-#ifdef PF_INET6
-			pai->ai_family = PF_INET6;
-#else
-			pai->ai_family = PF_INET;
-#endif
-		}
-		error = get_portmatch(pai, servname);
-		if (error)
-			ERR(error);
-
-		*pai = ai0;
-	}
-	ai0 = *pai;
-
-	/* NULL hostname, or numeric hostname */
-	for (ex = explore; ex->e_af >= 0; ex++) {
-		*pai = ai0;
-
-		/* PF_UNSPEC entries are prepared for DNS queries only */
-		if (ex->e_af == PF_UNSPEC)
-			continue;
-
-		if (!MATCH_FAMILY(pai->ai_family, ex->e_af, WILD_AF(ex)))
-			continue;
-		if (!MATCH(pai->ai_socktype, ex->e_socktype, WILD_SOCKTYPE(ex)))
-			continue;
-		if (!MATCH(pai->ai_protocol, ex->e_protocol, WILD_PROTOCOL(ex)))
-			continue;
-
-		if (pai->ai_family == PF_UNSPEC)
-			pai->ai_family = ex->e_af;
-		if (pai->ai_socktype == ANY && ex->e_socktype != ANY)
-			pai->ai_socktype = ex->e_socktype;
-		if (pai->ai_protocol == ANY && ex->e_protocol != ANY)
-			pai->ai_protocol = ex->e_protocol;
-
-		if (hostname == NULL)
-			error = explore_null(pai, servname, &cur->ai_next);
-		else
-			error = explore_numeric_scope(pai, hostname, servname, &cur->ai_next);
-
-		if (error)
-			goto free;
-
-		while (cur && cur->ai_next)
-			cur = cur->ai_next;
-	}
 
-	/*
-	 * XXX If numreic representation of AF1 can be interpreted as FQDN representation of AF2, we need to think again about the code below.
-	 */
-	if (sentinel.ai_next) {
-		numeric = 1;
-		goto good;
-	}
-	if (hostname == NULL)
-		ERR(EAI_NONAME);/* used to be EAI_NODATA */
-	if (pai->ai_flags & AI_NUMERICHOST)
-		ERR(EAI_NONAME);
-
-	if ((pai->ai_flags & AI_ADDRCONFIG) != 0 && !addrconfig(&ai0))
-		ERR(EAI_FAIL);
-
-	/*
-	 * hostname as alphabetical name. we would like to prefer AF_INET6 than AF_INET, so we'll make a outer loop by AFs.
-	 */
-	for (ex = explore; ex->e_af >= 0; ex++) {
-		*pai = ai0;
-
-		/* require exact match for family field */
-		if (pai->ai_family != ex->e_af)
-			continue;
-
-		if (!MATCH(pai->ai_socktype, ex->e_socktype,
-				WILD_SOCKTYPE(ex))) {
-			continue;
-		}
-		if (!MATCH(pai->ai_protocol, ex->e_protocol,
-				WILD_PROTOCOL(ex))) {
-			continue;
-		}
-		if (pai->ai_socktype == ANY && ex->e_socktype != ANY)
-			pai->ai_socktype = ex->e_socktype;
-		if (pai->ai_protocol == ANY && ex->e_protocol != ANY)
-			pai->ai_protocol = ex->e_protocol;
-
-		error = explore_fqdn(pai, hostname, servname,
-			&cur->ai_next);
-
-		while (cur && cur->ai_next)
-			cur = cur->ai_next;
-	}
-
-	/* XXX inhibit errors if we have the result */
-	if (sentinel.ai_next)
-		error = 0;
-
-good:
-	/*
-	 * ensure we return either: - error == 0, non-NULL *res - error != 0, NULL *res
-	 */
-	if (error == 0) {
-		if (sentinel.ai_next) {
-			/*
-			 * If the returned entry is for an active connection, and the given name is not numeric, reorder the list, so that the application would try the list in the most efficient order.
-			 */
-			if (hints == NULL || !(hints->ai_flags & AI_PASSIVE)) {
-				if (!numeric)
-					(void)reorder(&sentinel);
-			}
-			*res = sentinel.ai_next;
-			return SUCCESS;
-		} else
-			error = EAI_FAIL;
-	}
-free:
-bad:
-	if (sentinel.ai_next)
-		freeaddrinfo(sentinel.ai_next);
-	*res = NULL;
-	return error;
-}
-
-static int
-reorder(sentinel)
-	struct addrinfo *sentinel;
-{
-	struct addrinfo *ai, **aip;
-	struct ai_order *aio;
-	int i, n;
-	struct policyhead policyhead;
-
-	/* count the number of addrinfo elements for sorting. */
-	for (n = 0, ai = sentinel->ai_next; ai != NULL; ai = ai->ai_next, n++);
-
-	/*
-	 * If the number is small enough, we can skip the reordering process.
-	 */
-	if (n <= 1)
-		return (n);
-
-	/* allocate a temporary array for sort and initialization of it. */
-	if ((aio = malloc(sizeof(*aio) * n)) == NULL)
-		return (n);	/* give up reordering */
-	memset(aio, 0, sizeof(*aio) * n);
-
-	/* retrieve address selection policy from the kernel */
-	TAILQ_INIT(&policyhead);
-	if (!get_addrselectpolicy(&policyhead)) {
-		/* no policy is installed into kernel, we don't sort. */
-		free(aio);
-		return (n);
-	}
-	for (i = 0, ai = sentinel->ai_next; i < n; ai = ai->ai_next, i++) {
-		aio[i].aio_ai = ai;
-		aio[i].aio_dstscope = gai_addr2scopetype(ai->ai_addr);
-		aio[i].aio_dstpolicy = match_addrselectpolicy(ai->ai_addr,
-			&policyhead);
-	}
-
-	/* perform sorting. */
-	qsort(aio, n, sizeof(*aio), comp_dst);
-
-	/* reorder the addrinfo chain. */
-	for (i = 0, aip = &sentinel->ai_next; i < n; i++) {
-		*aip = aio[i].aio_ai;
-		aip = &aio[i].aio_ai->ai_next;
-	}
-	*aip = NULL;
-
-	/* cleanup and return */
-	free(aio);
-	free_addrselectpolicy(&policyhead);
-	return (n);
-}
-
-static int
-get_addrselectpolicy(head)
-	struct policyhead *head;
-{
-#ifdef INET6
-	int mib[] = {CTL_NET, PF_INET6, IPPROTO_IPV6, IPV6CTL_ADDRCTLPOLICY};
-	size_t l;
-	char *buf;
-	struct in6_addrpolicy *pol, *ep;
-
-	if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), NULL, &l, NULL, 0) < 0)
-		return (0);
-	if ((buf = malloc(l)) == NULL)
-		return (0);
-	if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), buf, &l, NULL, 0) < 0) {
-		free(buf);
-		return (0);
-	}
-	ep = (struct in6_addrpolicy *) (buf + l);
-	for (pol = (struct in6_addrpolicy *) buf; pol + 1 <= ep; pol++) {
-		struct policyqueue *new;
-
-		if ((new = malloc(sizeof(*new))) == NULL) {
-			free_addrselectpolicy(head);	/* make the list empty */
-			break;
-		}
-		new->pc_policy = *pol;
-		TAILQ_INSERT_TAIL(head, new, pc_entry);
-	}
-
-	free(buf);
-	return (1);
-#else
-	return (0);
-#endif
-}
-
-static void
-free_addrselectpolicy(head)
-	struct policyhead *head;
-{
-	struct policyqueue *ent, *nent;
-
-	for (ent = TAILQ_FIRST(head); ent; ent = nent) {
-		nent = TAILQ_NEXT(ent, pc_entry);
-		TAILQ_REMOVE(head, ent, pc_entry);
-		free(ent);
-	}
-}
-
-static struct policyqueue *
-match_addrselectpolicy(addr, head)
-	struct sockaddr *addr;
-	struct policyhead *head;
-{
-#ifdef INET6
-	struct policyqueue *ent, *bestent = NULL;
-	struct in6_addrpolicy *pol;
-	int matchlen, bestmatchlen = -1;
-	u_char *mp, *ep, *k, *p, m;
-	struct sockaddr_in6 key;
-
-	switch (addr->sa_family) {
-	case AF_INET6:
-		key = *(struct sockaddr_in6 *) addr;
-		break;
-	case AF_INET:
-		/* convert the address into IPv4-mapped IPv6 address. */
-		memset(&key, 0, sizeof(key));
-		key.sin6_family = AF_INET6;
-		key.sin6_len = sizeof(key);
-		key.sin6_addr.s6_addr[10] = 0xff;
-		key.sin6_addr.s6_addr[11] = 0xff;
-		memcpy(&key.sin6_addr.s6_addr[12],
-			&((struct sockaddr_in *) addr)->sin_addr, 4);
-		break;
-	default:
-		return (NULL);
-	}
-
-	for (ent = TAILQ_FIRST(head); ent; ent = TAILQ_NEXT(ent, pc_entry)) {
-		pol = &ent->pc_policy;
-		matchlen = 0;
-
-		mp = (u_char *) & pol->addrmask.sin6_addr;
-		ep = mp + 16;	/* XXX: scope field? */
-		k = (u_char *) & key.sin6_addr;
-		p = (u_char *) & pol->addr.sin6_addr;
-		for (; mp < ep && *mp; mp++, k++, p++) {
-			m = *mp;
-			if ((*k & m) != *p)
-				goto next;	/* not match */
-			if (m == 0xff)	/* short cut for a typical case */
-				matchlen += 8;
-			else {
-				while (m >= 0x80) {
-					matchlen++;
-					m <<= 1;
-				}
-			}
-		}
-
-		/* matched.  check if this is better than the current best. */
-		if (matchlen > bestmatchlen) {
-			bestent = ent;
-			bestmatchlen = matchlen;
-		}
-next:
-		continue;
-	}
-
-	return (bestent);
-#else
-	return (NULL);
-#endif
-
-}
-
-static int
-comp_dst(arg1, arg2)
-	const void *arg1, *arg2;
-{
-	const struct ai_order *dst1 = arg1, *dst2 = arg2;
-
-	/*
-	 * Rule 1: Avoid unusable destinations. XXX: we currently do not consider if an appropriate route exists.
-	 */
-	if (dst1->aio_srcsa.sa_family != AF_UNSPEC &&
-		dst2->aio_srcsa.sa_family == AF_UNSPEC) {
-		return (-1);
-	}
-	if (dst1->aio_srcsa.sa_family == AF_UNSPEC &&
-		dst2->aio_srcsa.sa_family != AF_UNSPEC) {
-		return (1);
-	}
-	/* Rule 2: Prefer matching scope. */
-	if (dst1->aio_dstscope == dst1->aio_srcscope &&
-		dst2->aio_dstscope != dst2->aio_srcscope) {
-		return (-1);
-	}
-	if (dst1->aio_dstscope != dst1->aio_srcscope &&
-		dst2->aio_dstscope == dst2->aio_srcscope) {
-		return (1);
-	}
-	/* Rule 3: Avoid deprecated addresses. */
-	if (dst1->aio_srcsa.sa_family != AF_UNSPEC &&
-		dst2->aio_srcsa.sa_family != AF_UNSPEC) {
-		if (!(dst1->aio_srcflag & AIO_SRCFLAG_DEPRECATED) &&
-			(dst2->aio_srcflag & AIO_SRCFLAG_DEPRECATED)) {
-			return (-1);
-		}
-		if ((dst1->aio_srcflag & AIO_SRCFLAG_DEPRECATED) &&
-			!(dst2->aio_srcflag & AIO_SRCFLAG_DEPRECATED)) {
-			return (1);
-		}
-	}
-	/* Rule 4: Prefer home addresses. */
-	/* XXX: not implemented yet */
-
-	/* Rule 5: Prefer matching label. */
-#ifdef INET6
-	if (dst1->aio_srcpolicy && dst1->aio_dstpolicy &&
-		dst1->aio_srcpolicy->pc_policy.label ==
-		dst1->aio_dstpolicy->pc_policy.label &&
-		(dst2->aio_srcpolicy == NULL || dst2->aio_dstpolicy == NULL ||
-			dst2->aio_srcpolicy->pc_policy.label !=
-			dst2->aio_dstpolicy->pc_policy.label)) {
-		return (-1);
-	}
-	if (dst2->aio_srcpolicy && dst2->aio_dstpolicy &&
-		dst2->aio_srcpolicy->pc_policy.label ==
-		dst2->aio_dstpolicy->pc_policy.label &&
-		(dst1->aio_srcpolicy == NULL || dst1->aio_dstpolicy == NULL ||
-			dst1->aio_srcpolicy->pc_policy.label !=
-			dst1->aio_dstpolicy->pc_policy.label)) {
-		return (1);
-	}
-#endif
-
-	/* Rule 6: Prefer higher precedence. */
-#ifdef INET6
-	if (dst1->aio_dstpolicy &&
-		(dst2->aio_dstpolicy == NULL ||
-			dst1->aio_dstpolicy->pc_policy.preced >
-			dst2->aio_dstpolicy->pc_policy.preced)) {
-		return (-1);
-	}
-	if (dst2->aio_dstpolicy &&
-		(dst1->aio_dstpolicy == NULL ||
-			dst2->aio_dstpolicy->pc_policy.preced >
-			dst1->aio_dstpolicy->pc_policy.preced)) {
-		return (1);
-	}
-#endif
-
-	/* Rule 7: Prefer native transport. */
-	/* XXX: not implemented yet */
-
-	/* Rule 8: Prefer smaller scope. */
-	if (dst1->aio_dstscope >= 0 &&
-		dst1->aio_dstscope < dst2->aio_dstscope) {
-		return (-1);
-	}
-	if (dst2->aio_dstscope >= 0 &&
-		dst2->aio_dstscope < dst1->aio_dstscope) {
-		return (1);
-	}
-	/*
-	 * Rule 9: Use longest matching prefix. We compare the match length in a same AF only.
-	 */
-	if (dst1->aio_ai->ai_addr->sa_family ==
-		dst2->aio_ai->ai_addr->sa_family) {
-		if (dst1->aio_matchlen > dst2->aio_matchlen) {
-			return (-1);
-		}
-		if (dst1->aio_matchlen < dst2->aio_matchlen) {
-			return (1);
-		}
-	}
-	/* Rule 10: Otherwise, leave the order unchanged. */
-	return (-1);
-}
-
-/*
- * Copy from scope.c. XXX: we should standardize the functions and link them as standard library.
- */
-static int
-gai_addr2scopetype(sa)
-	struct sockaddr *sa;
-{
-#ifdef INET6
-	struct sockaddr_in6 *sa6;
-#endif
-	struct sockaddr_in *sa4;
-
-	switch (sa->sa_family) {
-#ifdef INET6
-	case AF_INET6:
-		sa6 = (struct sockaddr_in6 *) sa;
-		if (IN6_IS_ADDR_MULTICAST(&sa6->sin6_addr)) {
-			/* just use the scope field of the multicast address */
-			return (sa6->sin6_addr.s6_addr[2] & 0x0f);
-		}
-		/*
-		 * Unicast addresses: map scope type to corresponding scope value defined for multcast addresses. XXX: hardcoded scope type values are bad...
-		 */
-		if (IN6_IS_ADDR_LOOPBACK(&sa6->sin6_addr))
-			return (1);	/* node local scope */
-		if (IN6_IS_ADDR_LINKLOCAL(&sa6->sin6_addr))
-			return (2);	/* link-local scope */
-		if (IN6_IS_ADDR_SITELOCAL(&sa6->sin6_addr))
-			return (5);	/* site-local scope */
-		return (14);	/* global scope */
-		break;
-#endif
-	case AF_INET:
-		/*
-		 * IPv4 pseudo scoping according to RFC 3484.
-		 */
-		sa4 = (struct sockaddr_in *) sa;
-		/* IPv4 autoconfiguration addresses have link-local scope. */
-		if (((u_char *) & sa4->sin_addr)[0] == 169 &&
-			((u_char *) & sa4->sin_addr)[1] == 254)
-			return (2);
-		/* Private addresses have site-local scope. */
-		if (((u_char *) & sa4->sin_addr)[0] == 10 ||
-			(((u_char *) & sa4->sin_addr)[0] == 172 &&
-				(((u_char *) & sa4->sin_addr)[1] & 0xf0) == 16) ||
-			(((u_char *) & sa4->sin_addr)[0] == 192 &&
-				((u_char *) & sa4->sin_addr)[1] == 168))
-			return (5);
-		/* Loopback addresses have link-local scope. */
-		if (((u_char *) & sa4->sin_addr)[0] == 127)
-			return (2);
-		return (14);
-		break;
-	default:
-		errno = EAFNOSUPPORT;	/* is this a good error? */
-		return (-1);
-	}
-}
-
-/*
- * hostname == NULL. passive socket -> anyaddr (0.0.0.0 or ::) non-passive socket -> localhost (127.0.0.1 or ::1)
- */
-static int
-explore_null(pai, servname, res)
-	const struct addrinfo *pai;
-	const char *servname;
-	struct addrinfo **res;
-{
-	int s;
-	const struct afd *afd;
-	struct addrinfo *cur;
-	struct addrinfo sentinel;
-	int error;
-
-	*res = NULL;
-	sentinel.ai_next = NULL;
-	cur = &sentinel;
-
-	/*
-	 * filter out AFs that are not supported by the kernel XXX errno?
-	 */
-	s = socket(pai->ai_family, SOCK_DGRAM, 0);
-	if (s < 0) {
-		if (errno != EMFILE)
-			return 0;
-	} else
-		close(s);
-
-	/*
-	 * if the servname does not match socktype/protocol, ignore it.
-	 */
-	if (get_portmatch(pai, servname) != 0)
-		return 0;
-
-	afd = find_afd(pai->ai_family);
-	if (afd == NULL)
-		return 0;
-
-	if (pai->ai_flags & AI_PASSIVE) {
-		GET_AI(cur->ai_next, afd, afd->a_addrany);
-		/*
-		 * xxx meaningless? GET_CANONNAME(cur->ai_next, "anyaddr");
-		 */
-		GET_PORT(cur->ai_next, servname);
-	} else {
-		GET_AI(cur->ai_next, afd, afd->a_loopback);
-		/*
-		 * xxx meaningless? GET_CANONNAME(cur->ai_next, "localhost");
-		 */
-		GET_PORT(cur->ai_next, servname);
-	}
-	cur = cur->ai_next;
-
-	*res = sentinel.ai_next;
-	return 0;
-
-free:
-	if (sentinel.ai_next)
-		freeaddrinfo(sentinel.ai_next);
-	return error;
-}
-
-/*
- * numeric hostname
- */
-static int
-explore_numeric(pai, hostname, servname, res)
-	const struct addrinfo *pai;
-	const char *hostname;
-	const char *servname;
-	struct addrinfo **res;
-{
-	const struct afd *afd;
-	struct addrinfo *cur;
-	struct addrinfo sentinel;
-	int error;
-	char pton[PTON_MAX];
+#define	DEBUG	1	/* enable debugging code (needed for dig) */
+#define	RESOLVSORT	/* allow sorting of addresses in gethostbyname */
 
-	*res = NULL;
-	sentinel.ai_next = NULL;
-	cur = &sentinel;
+#ifdef DEBUG
+#include <syslog.h>
+#endif
 
-	/*
-	 * if the servname does not match socktype/protocol, ignore it.
-	 */
-	if (get_portmatch(pai, servname) != 0)
-		return 0;
+#include <stdarg.h>
+#include <nsswitch.h>
 
-	afd = find_afd(pai->ai_family);
-	if (afd == NULL)
-		return 0;
+#ifndef res_ninit
+#define	res_ninit(r)			res_init()
+#define	res_nmkquery(r,a, b, c, d, e, f, g, h, i) \
+	res_mkquery(a, b, c, d, e, f, g, h, i)
+#define	res_nopt(r, a, b, c, d)		res_opt(a, b, c, d)
+#define	res_nsend(r, a, b, c, d)	res_send(a, b, c, d)
+#endif
+
+#ifndef res_hostalias
+extern const char *_res_hostalias(const char *, char *, size_t);
+#define	res_hostalias(a, b, c, d)	_res_hostalias(b, c, d)
+#endif
+
+#ifndef RES_SET_H_ERRNO
+typedef struct __res_state *res_state;
+#define	RES_SET_H_ERRNO(r,x)	h_errno
+#define	H_ERRNO(r)		h_errno
+#else
+#define	H_ERRNO(r)		(r)->res_h_errno
+#endif
 
-	switch (afd->a_af) {
-#if 1				/* X/Open spec */
-	case AF_INET:
-		if (inet_aton(hostname, (struct in_addr *) pton) == 1) {
-			if (pai->ai_family == afd->a_af ||
-				pai->ai_family == PF_UNSPEC /* ? */ ) {
-				GET_AI(cur->ai_next, afd, pton);
-				GET_PORT(cur->ai_next, servname);
-				while (cur && cur->ai_next)
-					cur = cur->ai_next;
-			} else
-				ERR(EAI_FAMILY);	/* xxx */
-		}
-		break;
+#ifndef RES_USE_DNSSEC
+#define	RES_USE_DNSSEC	0
 #endif
-	default:
-		if (inet_pton(afd->a_af, hostname, pton) == 1) {
-			if (pai->ai_family == afd->a_af ||
-				pai->ai_family == PF_UNSPEC /* ? */ ) {
-				GET_AI(cur->ai_next, afd, pton);
-				GET_PORT(cur->ai_next, servname);
-				while (cur && cur->ai_next)
-					cur = cur->ai_next;
-			} else
-				ERR(EAI_FAMILY);	/* XXX */
-		}
-		break;
-	}
 
-	*res = sentinel.ai_next;
-	return 0;
+#if defined(__KAME__) && defined(INET6)
+# define FAITH
+#endif
 
-free:
-bad:
-	if (sentinel.ai_next)
-		freeaddrinfo(sentinel.ai_next);
-	return error;
-}
+static const char in_addrany[] = { 0, 0, 0, 0 };
+static const char in_loopback[] = { 127, 0, 0, 1 };
+#ifdef INET6
+static const char in6_addrany[] = {
+	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
+};
+static const char in6_loopback[] = {
+	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
+};
+#endif
 
-/*
- * numeric hostname with scope
- */
-static int
-explore_numeric_scope(pai, hostname, servname, res)
-	const struct addrinfo *pai;
-	const char *hostname;
-	const char *servname;
-	struct addrinfo **res;
-{
-#if !defined(SCOPE_DELIMITER) || !defined(INET6)
-	return explore_numeric(pai, hostname, servname, res);
+static const struct afd {
+	int a_af;
+	int a_addrlen;
+	socklen_t a_socklen;
+	int a_off;
+	const char *a_addrany;
+	const char *a_loopback;
+	int a_scoped;
+} afdl [] = {
+#ifdef INET6
+#define	N_INET6 0
+	{PF_INET6, sizeof(struct in6_addr),
+	 sizeof(struct sockaddr_in6),
+	 offsetof(struct sockaddr_in6, sin6_addr),
+	 in6_addrany, in6_loopback, 1},
+#define	N_INET 1
 #else
-	const struct afd *afd;
-	struct addrinfo *cur;
-	int error;
-	char *cp, *hostname2 = NULL, *scope, *addr;
-	struct sockaddr_in6 *sin6;
+#define	N_INET 0
+#endif
+	{PF_INET, sizeof(struct in_addr),
+	 sizeof(struct sockaddr_in),
+	 offsetof(struct sockaddr_in, sin_addr),
+	 in_addrany, in_loopback, 0},
+	{0, 0, 0, 0, NULL, NULL, 0},
+};
 
-	/*
-	 * if the servname does not match socktype/protocol, ignore it.
-	 */
-	if (get_portmatch(pai, servname) != 0)
-		return 0;
+struct res_target {
+	struct res_target *next;
+	const char *name;	/* domain name */
+	int qclass, qtype;	/* class and type of query */
+	u_char *answer;		/* buffer to put answer */
+	int anslen;		/* size of answer buffer */
+	int n;			/* result length */
+};
 
-	afd = find_afd(pai->ai_family);
-	if (afd == NULL)
-		return 0;
+#define MAXPACKET	(64*1024)
 
-	if (!afd->a_scoped)
-		return explore_numeric(pai, hostname, servname, res);
+typedef union {
+	HEADER hdr;
+	u_char buf[MAXPACKET];
+} querybuf;
 
-	cp = strchr(hostname, SCOPE_DELIMITER);
-	if (cp == NULL)
-		return explore_numeric(pai, hostname, servname, res);
+static int get_canonname(const struct addrinfo *,
+	struct addrinfo *, const char *);
+static struct addrinfo *get_ai(const struct addrinfo *,
+	const struct afd *, const char *);
+static const struct afd *find_afd(int);
+static struct addrinfo *getanswer(const querybuf *, int, const char *, int,
+	const struct addrinfo *, res_state);
+#if defined(RESOLVSORT)
+static int addr4sort(struct addrinfo *, res_state);
+#endif
 
-	/*
-	 * Handle special case of <scoped_address><delimiter><scope id>
-	 */
-	hostname2 = strdup(hostname);
-	if (hostname2 == NULL)
-		return EAI_MEMORY;
-	/* terminate at the delimiter */
-	hostname2[cp - hostname] = '\0';
-	addr = hostname2;
-	scope = cp + 1;
-
-	error = explore_numeric(pai, addr, servname, res);
-	if (error == 0) {
-		u_int32_t scopeid;
+static int res_queryN(const char *, struct res_target *, res_state);
+static int res_searchN(const char *, struct res_target *, res_state);
+static int res_querydomainN(const char *, const char *,
+	struct res_target *, res_state);
 
-		for (cur = *res; cur; cur = cur->ai_next) {
-			if (cur->ai_family != AF_INET6)
-				continue;
-			sin6 = (struct sockaddr_in6 *) (void *)cur->ai_addr;
-			if (ip6_str2scopeid(scope, sin6, &scopeid) == -1) {
-				free(hostname2);
-				return (EAI_NONAME);	/* XXX: is return OK? */
-			}
-			sin6->sin6_scope_id = scopeid;
-		}
-	}
-	free(hostname2);
+/* XXX macros that make external reference is BAD. */
 
-	return error;
-#endif
-}
+#define GET_AI(ai, afd, addr) \
+do { \
+	/* external reference: pai, error, and label free */ \
+	(ai) = get_ai(pai, (afd), (addr)); \
+	if ((ai) == NULL) { \
+		error = EAI_MEMORY; \
+		goto free; \
+	} \
+} while (/*CONSTCOND*/0)
 
 static int
-get_canonname(pai, ai, str)
-	const struct addrinfo *pai;
-	struct addrinfo *ai;
-	const char *str;
+get_canonname(const struct addrinfo *pai, struct addrinfo *ai, const char *str)
 {
 	if ((pai->ai_flags & AI_CANONNAME) != 0) {
-		ai->ai_canonname = (char *)malloc(strlen(str) + 1);
+		ai->ai_canonname = strdup(str);
 		if (ai->ai_canonname == NULL)
 			return EAI_MEMORY;
-		strlcpy(ai->ai_canonname, str, strlen(str) + 1);
 	}
 	return 0;
 }
 
 static struct addrinfo *
-get_ai(pai, afd, addr)
-	const struct addrinfo *pai;
-	const struct afd *afd;
-	const char *addr;
+get_ai(const struct addrinfo *pai, const struct afd *afd, const char *addr)
 {
 	char *p;
 	struct addrinfo *ai;
@@ -1170,148 +224,63 @@
 
 #ifdef FAITH
 	/*
-	 * Transfrom an IPv4 addr into a special IPv6 addr format for IPv6->IPv4 translation gateway. (only TCP is supported now)
-	 * 
-	 * +-----------------------------------+------------+ | faith prefix part (12 bytes)      | embedded   | |                                   | IPv4 addr part (4 bytes) +-----------------------------------+------------+
-	 * 
-	 * faith prefix part is specified as ascii IPv6 addr format in environmental variable GAI. For FAITH to work correctly, routing to faith prefix must be setup toward a machine where a FAITH daemon operates. Also, the machine must enable some mechanizm (e.g. faith interface hack) to divert those packet with faith prefixed destination addr to user-land FAITH daemon.
+	 * Transfrom an IPv4 addr into a special IPv6 addr format for
+	 * IPv6->IPv4 translation gateway. (only TCP is supported now)
+	 *
+	 * +-----------------------------------+------------+
+	 * | faith prefix part (12 bytes)      | embedded   |
+	 * |                                   | IPv4 addr part (4 bytes)
+	 * +-----------------------------------+------------+
+	 *
+	 * faith prefix part is specified as ascii IPv6 addr format
+	 * in environmental variable GAI.
+	 * For FAITH to work correctly, routing to faith prefix must be
+	 * setup toward a machine where a FAITH daemon operates.
+	 * Also, the machine must enable some mechanizm
+	 * (e.g. faith interface hack) to divert those packet with
+	 * faith prefixed destination addr to user-land FAITH daemon.
 	 */
 	fp_str = getenv("GAI");
 	if (fp_str && inet_pton(AF_INET6, fp_str, &faith_prefix) == 1 &&
-		afd->a_af == AF_INET && pai->ai_socktype == SOCK_STREAM) {
+	    afd->a_af == AF_INET && pai->ai_socktype == SOCK_STREAM) {
 		u_int32_t v4a;
 		u_int8_t v4a_top;
 
 		memcpy(&v4a, addr, sizeof v4a);
 		v4a_top = v4a >> IN_CLASSA_NSHIFT;
 		if (!IN_MULTICAST(v4a) && !IN_EXPERIMENTAL(v4a) &&
-			v4a_top != 0 && v4a != IN_LOOPBACKNET) {
+		    v4a_top != 0 && v4a != IN_LOOPBACKNET) {
 			afd = &afdl[N_INET6];
 			memcpy(&faith_prefix.s6_addr[12], addr,
-				sizeof(struct in_addr));
+			       sizeof(struct in_addr));
 			translate = 1;
 		}
 	}
 #endif
 
-	ai = (struct addrinfo *) malloc(sizeof(struct addrinfo)
+	ai = (struct addrinfo *)malloc(sizeof(struct addrinfo)
 		+ (afd->a_socklen));
 	if (ai == NULL)
 		return NULL;
 
 	memcpy(ai, pai, sizeof(struct addrinfo));
-	ai->ai_addr = (struct sockaddr *) (void *)(ai + 1);
-	memset(ai->ai_addr, 0, (size_t) afd->a_socklen);
+	ai->ai_addr = (struct sockaddr *)(void *)(ai + 1);
+	memset(ai->ai_addr, 0, (size_t)afd->a_socklen);
 	ai->ai_addr->sa_len = afd->a_socklen;
 	ai->ai_addrlen = afd->a_socklen;
 	ai->ai_addr->sa_family = ai->ai_family = afd->a_af;
 	p = (char *)(void *)(ai->ai_addr);
 #ifdef FAITH
 	if (translate == 1)
-		memcpy(p + afd->a_off, &faith_prefix, (size_t) afd->a_addrlen);
+		memcpy(p + afd->a_off, &faith_prefix, (size_t)afd->a_addrlen);
 	else
 #endif
-		memcpy(p + afd->a_off, addr, (size_t) afd->a_addrlen);
+	memcpy(p + afd->a_off, addr, (size_t)afd->a_addrlen);
 	return ai;
 }
 
-static int
-get_portmatch(ai, servname)
-	const struct addrinfo *ai;
-	const char *servname;
-{
-
-	/* get_port does not touch first argument. when matchonly == 1. */
-	/* LINTED const cast */
-	return get_port((struct addrinfo *) ai, servname, 1);
-}
-
-static int
-get_port(ai, servname, matchonly)
-	struct addrinfo *ai;
-	const char *servname;
-	int matchonly;
-{
-	const char *proto;
-	struct servent *sp;
-	int port;
-	int allownumeric;
-
-	if (servname == NULL)
-		return 0;
-	switch (ai->ai_family) {
-	case AF_INET:
-#ifdef AF_INET6
-	case AF_INET6:
-#endif
-		break;
-	default:
-		return 0;
-	}
-
-	switch (ai->ai_socktype) {
-	case SOCK_RAW:
-		return EAI_SERVICE;
-	case SOCK_DGRAM:
-	case SOCK_STREAM:
-		allownumeric = 1;
-		break;
-	case ANY:
-		allownumeric = 0;
-		break;
-	default:
-		return EAI_SOCKTYPE;
-	}
-
-	if (str_isnumber(servname)) {
-		if (!allownumeric)
-			return EAI_SERVICE;
-		port = atoi(servname);
-		if (port < 0 || port > 65535)
-			return EAI_SERVICE;
-		port = htons(port);
-	} else {
-		switch (ai->ai_socktype) {
-		case SOCK_DGRAM:
-			proto = "udp";
-			break;
-		case SOCK_STREAM:
-			proto = "tcp";
-			break;
-		default:
-			proto = NULL;
-			break;
-		}
-
-		THREAD_LOCK();
-		if ((sp = getservbyname(servname, proto)) == NULL) {
-			THREAD_UNLOCK();
-			return EAI_SERVICE;
-		}
-		port = sp->s_port;
-		THREAD_UNLOCK();
-	}
-
-	if (!matchonly) {
-		switch (ai->ai_family) {
-		case AF_INET:
-			((struct sockaddr_in *) (void *)
-				ai->ai_addr)->sin_port = port;
-			break;
-#ifdef INET6
-		case AF_INET6:
-			((struct sockaddr_in6 *) (void *)
-				ai->ai_addr)->sin6_port = port;
-			break;
-#endif
-		}
-	}
-	return 0;
-}
-
 static const struct afd *
-find_afd(af)
-	int af;
+find_afd(int af)
 {
 	const struct afd *afd;
 
@@ -1324,173 +293,29 @@
 	return NULL;
 }
 
-/*
- * post-2553: AI_ADDRCONFIG check.  if we use getipnodeby* as backend, backend will take care of it. the semantics of AI_ADDRCONFIG is not defined well.  we are not sure if the code is right or not.
- * 
- * XXX PF_UNSPEC -> PF_INET6 + PF_INET mapping needs to be in sync with _dns_getaddrinfo.
- */
-static int
-addrconfig(pai)
-	struct addrinfo *pai;
-{
-	int s, af;
-
-	/*
-	 * TODO: Note that implementation dependent test for address configuration should be done everytime called (or apropriate interval), because addresses will be dynamically assigned or deleted.
-	 */
-	af = pai->ai_family;
-	if (af == AF_UNSPEC) {
-		if ((s = socket(AF_INET6, SOCK_DGRAM, 0)) < 0)
-			af = AF_INET;
-		else {
-			close(s);
-			if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
-				af = AF_INET6;
-			else
-				close(s);
-		}
-	}
-	if (af != AF_UNSPEC) {
-		if ((s = socket(af, SOCK_DGRAM, 0)) < 0)
-			return 0;
-		close(s);
-	}
-	pai->ai_family = af;
-	return 1;
-}
-
-#ifdef INET6
-/* convert a string to a scope identifier. XXX: IPv6 specific */
-static int
-ip6_str2scopeid(scope, sin6, scopeid)
-	char *scope;
-	struct sockaddr_in6 *sin6;
-	u_int32_t *scopeid;
-{
-	u_long lscopeid;
-	struct in6_addr *a6;
-	char *ep;
-
-	a6 = &sin6->sin6_addr;
-
-	/* empty scopeid portion is invalid */
-	if (*scope == '\0')
-		return -1;
-
-	if (IN6_IS_ADDR_LINKLOCAL(a6) || IN6_IS_ADDR_MC_LINKLOCAL(a6)) {
-		/*
-		 * We currently assume a one-to-one mapping between links and interfaces, so we simply use interface indices for like-local scopes.
-		 */
-		*scopeid = if_nametoindex(scope);
-		if (*scopeid == 0)
-			goto trynumeric;
-		return 0;
-	}
-	/* still unclear about literal, allow numeric only - placeholder */
-	if (IN6_IS_ADDR_SITELOCAL(a6) || IN6_IS_ADDR_MC_SITELOCAL(a6))
-		goto trynumeric;
-	if (IN6_IS_ADDR_MC_ORGLOCAL(a6))
-		goto trynumeric;
-	else
-		goto trynumeric;/* global */
-
-	/* try to convert to a numeric id as a last resort */
-trynumeric:
-	errno = 0;
-	lscopeid = strtoul(scope, &ep, 10);
-	*scopeid = (u_int32_t) (lscopeid & 0xffffffffUL);
-	if (errno == 0 && ep && *ep == '\0' && *scopeid == lscopeid)
-		return 0;
-	else
-		return -1;
-}
-#endif
-
-/*
- * FQDN hostname, DNS lookup
- */
-static int
-explore_fqdn(pai, hostname, servname, res)
-	const struct addrinfo *pai;
-	const char *hostname;
-	const char *servname;
-	struct addrinfo **res;
-{
-	struct addrinfo *result;
-	struct addrinfo *cur;
-	int error = 0;
-	/*
-	 * static const ns_dtab dtab[] = { NS_FILES_CB(_files_getaddrinfo, NULL) { NSSRC_DNS, _dns_getaddrinfo, NULL },	// force -DHESIOD NS_NIS_CB(_yp_getaddrinfo, NULL) { 0 } };
-	 */
-
-	result = NULL;
-
-	/*
-	 * if the servname does not match socktype/protocol, ignore it.
-	 */
-	if (get_portmatch(pai, servname) != 0)
-		return 0;
-
-	/*
-	 * switch (_nsdispatch(&result, dtab, NSDB_HOSTS, "getaddrinfo", default_dns_files, hostname, pai)) {
-	 */
-	switch (lookupd_dns_getaddrinfo(&result, hostname, pai)) {
-	case NS_TRYAGAIN:
-		error = EAI_AGAIN;
-		goto free;
-	case NS_UNAVAIL:
-		error = EAI_FAIL;
-		goto free;
-	case NS_NOTFOUND:
-		error = EAI_NONAME;
-		goto free;
-	case NS_SUCCESS:
-		error = 0;
-		for (cur = result; cur; cur = cur->ai_next) {
-			GET_PORT(cur, servname);
-			/* canonname should be filled already */
-		}
-		break;
-	}
-
-	*res = result;
-
-	return 0;
-
-free:
-	if (result)
-		freeaddrinfo(result);
-	return error;
-}
-
 #ifdef DEBUG
 static const char AskedForGot[] =
-"gethostby*.getanswer: asked for \"%s\", got \"%s\"";
+	"gethostby*.getanswer: asked for \"%s\", got \"%s\"";
 #endif
-/* static FILE *hostf = NULL; */
 
 static struct addrinfo *
-getanswer(answer, anslen, qname, qtype, pai)
-const querybuf * answer;
-	int anslen;
-	const char *qname;
-	int qtype;
-	const struct addrinfo *pai;
+getanswer(const querybuf *answer, int anslen, const char *qname, int qtype,
+    const struct addrinfo *pai, res_state res)
 {
 	struct addrinfo sentinel, *cur;
 	struct addrinfo ai;
 	const struct afd *afd;
 	char *canonname;
-	const HEADER * hp;
-	const u_char * cp;
+	const HEADER *hp;
+	const u_char *cp;
 	int n;
-	const u_char * eom;
+	const u_char *eom;
 	char *bp, *ep;
 	int type, class, ancount, qdcount;
 	int haveanswer, had_error;
 	char tbuf[MAXDNAME];
-	int (*name_ok) (const char *);
-	char hostbuf[8 * 1024];
+	int (*name_ok)(const char *);
+	char hostbuf[8*1024];
 
 	memset(&sentinel, 0, sizeof(sentinel));
 	cur = &sentinel;
@@ -1500,8 +325,8 @@
 	switch (qtype) {
 	case T_A:
 	case T_AAAA:
-	case T_ANY:		/* use T_ANY only for T_A/T_AAAA lookup */
-		name_ok = lookupd_res_hnok;
+	case T_ANY:	/*use T_ANY only for T_A/T_AAAA lookup*/
+		name_ok = res_hnok;
 		break;
 	default:
 		return (NULL);	/* XXX should be abort(); */
@@ -1516,22 +341,23 @@
 	ep = hostbuf + sizeof hostbuf;
 	cp = answer->buf + HFIXEDSZ;
 	if (qdcount != 1) {
-		h_errno = NO_RECOVERY;
+		RES_SET_H_ERRNO(res, NO_RECOVERY);
 		return (NULL);
 	}
 	n = dn_expand(answer->buf, eom, cp, bp, ep - bp);
-	if ((n < 0) || !(*name_ok) (bp)) {
-		h_errno = NO_RECOVERY;
+	if ((n < 0) || !(*name_ok)(bp)) {
+		RES_SET_H_ERRNO(res, NO_RECOVERY);
 		return (NULL);
 	}
 	cp += n + QFIXEDSZ;
 	if (qtype == T_A || qtype == T_AAAA || qtype == T_ANY) {
-		/*
-		 * res_send() has already verified that the query name is the same as the one we sent; this just gets the expanded name (i.e., with the succeeding search-domain tacked on).
+		/* res_send() has already verified that the query name is the
+		 * same as the one we sent; this just gets the expanded name
+		 * (i.e., with the succeeding search-domain tacked on).
 		 */
-		n = strlen(bp) + 1;	/* for the \0 */
+		n = strlen(bp) + 1;		/* for the \0 */
 		if (n >= MAXHOSTNAMELEN) {
-			h_errno = NO_RECOVERY;
+			RES_SET_H_ERRNO(res, NO_RECOVERY);
 			return (NULL);
 		}
 		canonname = bp;
@@ -1543,26 +369,26 @@
 	had_error = 0;
 	while (ancount-- > 0 && cp < eom && !had_error) {
 		n = dn_expand(answer->buf, eom, cp, bp, ep - bp);
-		if ((n < 0) || !(*name_ok) (bp)) {
+		if ((n < 0) || !(*name_ok)(bp)) {
 			had_error++;
 			continue;
 		}
-		cp += n;	/* name */
+		cp += n;			/* name */
 		type = _getshort(cp);
-		cp += INT16SZ;	/* type */
+ 		cp += INT16SZ;			/* type */
 		class = _getshort(cp);
-		cp += INT16SZ + INT32SZ;	/* class, TTL */
+ 		cp += INT16SZ + INT32SZ;	/* class, TTL */
 		n = _getshort(cp);
-		cp += INT16SZ;	/* len */
+		cp += INT16SZ;			/* len */
 		if (class != C_IN) {
 			/* XXX - debug? syslog? */
 			cp += n;
-			continue;	/* XXX - had_error++ ? */
+			continue;		/* XXX - had_error++ ? */
 		}
 		if ((qtype == T_A || qtype == T_AAAA || qtype == T_ANY) &&
-			type == T_CNAME) {
+		    type == T_CNAME) {
 			n = dn_expand(answer->buf, eom, cp, tbuf, sizeof tbuf);
-			if ((n < 0) || !(*name_ok) (tbuf)) {
+			if ((n < 0) || !(*name_ok)(tbuf)) {
 				had_error++;
 				continue;
 			}
@@ -1586,21 +412,21 @@
 		} else if (type != qtype) {
 #ifdef DEBUG
 			if (type != T_KEY && type != T_SIG)
-				syslog(LOG_NOTICE | LOG_AUTH,
-					"gethostby*.getanswer: asked for \"%s %s %s\", got type \"%s\"",
-					qname, p_class(C_IN), p_type(qtype),
-					p_type(type));
+				syslog(LOG_NOTICE|LOG_AUTH,
+	       "gethostby*.getanswer: asked for \"%s %s %s\", got type \"%s\"",
+				       qname, p_class(C_IN), p_type(qtype),
+				       p_type(type));
 #endif
 			cp += n;
-			continue;	/* XXX - had_error++ ? */
+			continue;		/* XXX - had_error++ ? */
 		}
 		switch (type) {
 		case T_A:
 		case T_AAAA:
 			if (strcasecmp(canonname, bp) != 0) {
 #ifdef DEBUG
-				syslog(LOG_NOTICE | LOG_AUTH,
-					AskedForGot, canonname, bp);
+				syslog(LOG_NOTICE|LOG_AUTH,
+				       AskedForGot, canonname, bp);
 #endif
 				cp += n;
 				continue;	/* XXX - had_error++ ? */
@@ -1630,6 +456,7 @@
 				nn = strlen(bp) + 1;	/* for the \0 */
 				bp += nn;
 			}
+
 			/* don't overwrite pai */
 			ai = *pai;
 			ai.ai_family = (type == T_A) ? AF_INET : AF_INET6;
@@ -1654,24 +481,26 @@
 	if (haveanswer) {
 #if defined(RESOLVSORT)
 		/*
-		 * We support only IPv4 address for backward compatibility against gethostbyname(3).
+		 * We support only IPv4 address for backward
+		 * compatibility against gethostbyname(3).
 		 */
-		if (_res.nsort && qtype == T_A) {
-			if (addr4sort(&sentinel) < 0) {
+		if (res->nsort && qtype == T_A) {
+			if (addr4sort(&sentinel, res) < 0) {
 				freeaddrinfo(sentinel.ai_next);
-				h_errno = NO_RECOVERY;
+				RES_SET_H_ERRNO(res, NO_RECOVERY);
 				return NULL;
 			}
 		}
-#endif				/* RESOLVSORT */
+#endif /*RESOLVSORT*/
 		if (!canonname)
 			(void)get_canonname(pai, sentinel.ai_next, qname);
 		else
 			(void)get_canonname(pai, sentinel.ai_next, canonname);
-		h_errno = NETDB_SUCCESS;
+		RES_SET_H_ERRNO(res, NETDB_SUCCESS);
 		return sentinel.ai_next;
 	}
-	h_errno = NO_RECOVERY;
+
+	RES_SET_H_ERRNO(res, NO_RECOVERY);
 	return NULL;
 }
 
@@ -1682,7 +511,7 @@
 };
 
 static int
-addr4sort(struct addrinfo * sentinel)
+addr4sort(struct addrinfo *sentinel, res_state res)
 {
 	struct addrinfo *ai;
 	struct addr_ptr *addrs, addr;
@@ -1696,15 +525,15 @@
 	for (ai = sentinel->ai_next; ai; ai = ai->ai_next)
 		naddrs++;
 	if (naddrs < 2)
-		return 0;	/* We don't need sorting. */
+		return 0;		/* We don't need sorting. */
 	if ((addrs = malloc(sizeof(struct addr_ptr) * naddrs)) == NULL)
 		return -1;
 	i = 0;
 	for (ai = sentinel->ai_next; ai; ai = ai->ai_next) {
-		sin = (struct sockaddr_in *) ai->ai_addr;
-		for (j = 0; (unsigned)j < _res.nsort; j++) {
-			if (_res.sort_list[j].addr.s_addr ==
-				(sin->sin_addr.s_addr & _res.sort_list[j].mask))
+		sin = (struct sockaddr_in *)ai->ai_addr;
+		for (j = 0; (unsigned)j < res->nsort; j++) {
+			if (res->sort_list[j].addr.s_addr ==
+			    (sin->sin_addr.s_addr & res->sort_list[j].mask))
 				break;
 		}
 		addrs[i].ai = ai;
@@ -1717,16 +546,17 @@
 		free(addrs);
 		return 0;
 	}
+
 	while (needsort < naddrs) {
-		for (j = needsort - 1; j >= 0; j--) {
-			if (addrs[j].aval > addrs[j + 1].aval) {
-				addr = addrs[j];
-				addrs[j] = addrs[j + 1];
-				addrs[j + 1] = addr;
-			} else
-				break;
-		}
-		needsort++;
+	    for (j = needsort - 1; j >= 0; j--) {
+		if (addrs[j].aval > addrs[j+1].aval) {
+		    addr = addrs[j];
+		    addrs[j] = addrs[j + 1];
+		    addrs[j + 1] = addr;
+		} else
+		    break;
+	    }
+	    needsort++;
 	}
 
 	ai = sentinel;
@@ -1738,56 +568,58 @@
 	free(addrs);
 	return 0;
 }
-#endif				/* RESOLVSORT */
+#endif /*RESOLVSORT*/
 
 int
-lookupd_dns_getaddrinfo(void *rv, const char *name, const struct addrinfo * pai)
+lookupd_dns_getaddrinfo(void *rv, const char *hostname,
+    const struct addrinfo *pai)
 {
 	struct addrinfo *ai;
 	querybuf *buf, *buf2;
 	struct addrinfo sentinel, *cur;
 	struct res_target q, q2;
+	res_state res;
 
-	memset(&q, 0, sizeof(q2));
+	memset(&q, 0, sizeof(q));
 	memset(&q2, 0, sizeof(q2));
 	memset(&sentinel, 0, sizeof(sentinel));
 	cur = &sentinel;
 
 	buf = malloc(sizeof(*buf));
 	if (!buf) {
-		h_errno = NETDB_INTERNAL;
+		RES_SET_H_ERRNO(res, NETDB_INTERNAL);
 		return NS_NOTFOUND;
 	}
 	buf2 = malloc(sizeof(*buf2));
 	if (!buf2) {
 		free(buf);
-		h_errno = NETDB_INTERNAL;
+		RES_SET_H_ERRNO(res, NETDB_INTERNAL);
 		return NS_NOTFOUND;
 	}
+
 	switch (pai->ai_family) {
 	case AF_UNSPEC:
-		/* prefer IPv6 */
-		q.name = name;
+		q.name = hostname;
 		q.qclass = C_IN;
-		q.qtype = T_AAAA;
+		q.qtype = T_A;
 		q.answer = buf->buf;
 		q.anslen = sizeof(buf->buf);
 		q.next = &q2;
-		q2.name = name;
+		q2.name = hostname;
 		q2.qclass = C_IN;
-		q2.qtype = T_A;
+		q2.qtype = T_AAAA;
 		q2.answer = buf2->buf;
 		q2.anslen = sizeof(buf2->buf);
 		break;
 	case AF_INET:
-		q.name = name;
+		q.name = hostname;
 		q.qclass = C_IN;
 		q.qtype = T_A;
 		q.answer = buf->buf;
 		q.anslen = sizeof(buf->buf);
 		break;
 	case AF_INET6:
-		q.name = name;
+		q.name = hostname;
 		q.qclass = C_IN;
 		q.qtype = T_AAAA;
 		q.answer = buf->buf;
@@ -1799,26 +631,35 @@
 		return NS_UNAVAIL;
 	}
 
-	if (res_searchN(name, &q) < 0) {
+	res = &_res;
+	if ((res->options & RES_INIT) == 0 && res_ninit(res) == -1) {
+		RES_SET_H_ERRNO(res, NETDB_INTERNAL);
 		free(buf);
 		free(buf2);
 		return NS_NOTFOUND;
 	}
-	ai = getanswer(buf, q.n, q.name, q.qtype, pai);
-	if (ai) {
-		cur->ai_next = ai;
-		while (cur && cur->ai_next)
-			cur = cur->ai_next;
+
+	if (res_searchN(hostname, &q, res) < 0) {
+		free(buf);
+		free(buf2);
+		return NS_NOTFOUND;
 	}
+	/* prefer IPv6 */
 	if (q.next) {
-		ai = getanswer(buf2, q2.n, q2.name, q2.qtype, pai);
-		if (ai)
+		ai = getanswer(buf2, q2.n, q2.name, q2.qtype, pai, res);
+		if (ai) {
 			cur->ai_next = ai;
+			while (cur && cur->ai_next)
+				cur = cur->ai_next;
+		}
 	}
+	ai = getanswer(buf, q.n, q.name, q.qtype, pai, res);
+	if (ai)
+		cur->ai_next = ai;
 	free(buf);
 	free(buf2);
 	if (sentinel.ai_next == NULL)
-		switch (h_errno) {
+		switch (H_ERRNO(res)) {
 		case HOST_NOT_FOUND:
 			return NS_NOTFOUND;
 		case TRY_AGAIN:
@@ -1826,28 +667,31 @@
 		default:
 			return NS_UNAVAIL;
 		}
-
-	*((struct addrinfo **) rv) = sentinel.ai_next;
+	*((struct addrinfo **)rv) = sentinel.ai_next;
 	return NS_SUCCESS;
 }
 
 /* resolver logic */
 
-extern const char *__hostalias(const char *);
-
 /*
- * Formulate a normal query, send, and await answer. Returned answer is placed in supplied buffer "answer". Perform preliminary check of answer, returning success only if no error is indicated and the answer count is nonzero. Return the size of the response on success, -1 on error. Error number is left in h_errno.
- * 
+ * Formulate a normal query, send, and await answer.
+ * Returned answer is placed in supplied buffer "answer".
+ * Perform preliminary check of answer, returning success only
+ * if no error is indicated and the answer count is nonzero.
+ * Return the size of the response on success, -1 on error.
+ * Error number is left in h_errno.
+ *
  * Caller must parse answer and determine whether it answers the question.
  */
 static int
-res_queryN(name, target)
-	const char *name;	/* domain name */
-	struct res_target *target;
+res_queryN(const char *name, struct res_target *target, res_state res)
 {
 	u_char *buf;
 	HEADER *hp;
 	int n;
+#ifdef RES_F_EDNS0ERR
+	u_int oflags;
+#endif
 	struct res_target *t;
 	int rcode;
 	int ancount;
@@ -1855,70 +699,90 @@
 	rcode = NOERROR;
 	ancount = 0;
 
-	if ((_res.options & RES_INIT) == 0 && lookupd_res_init() == -1) {
-		h_errno = NETDB_INTERNAL;
-		return (-1);
-	}
 	buf = malloc(MAXPACKET);
 	if (!buf) {
-		h_errno = NETDB_INTERNAL;
+		RES_SET_H_ERRNO(res, NETDB_INTERNAL);
 		return -1;
 	}
+
 	for (t = target; t; t = t->next) {
 		int class, type;
 		u_char *answer;
 		int anslen;
 
-		hp = (HEADER *) (void *)t->answer;
-		hp->rcode = NOERROR;	/* default */
+		hp = (HEADER *)(void *)t->answer;
 
 		/* make it easier... */
 		class = t->qclass;
 		type = t->qtype;
 		answer = t->answer;
 		anslen = t->anslen;
+
+#ifdef RES_F_EDNS0ERR
+		oflags = res->_flags;
+
+again:
+#endif
+		hp->rcode = NOERROR;	/* default */
+
 #ifdef DEBUG
-		if (_res.options & RES_DEBUG)
+		if (res->options & RES_DEBUG)
 			printf(";; res_query(%s, %d, %d)\n", name, class, type);
 #endif
 
-		n = lookupd_res_mkquery(QUERY, name, class, type, NULL, 0, NULL,
-			buf, MAXPACKET);
-		if (n > 0 && (_res.options & RES_USE_EDNS0) != 0)
-			n = lookupd_res_opt(n, buf, MAXPACKET, anslen);
+		n = res_nmkquery(res, QUERY, name, class, type, NULL, 0, NULL,
+		    buf, MAXPACKET);
+		if (n > 0 &&
+#ifdef RES_F_EDNS0ERR
+		    (res->_flags & RES_F_EDNS0ERR) == 0 &&
+#endif
+		    (res->options & (RES_USE_EDNS0|RES_USE_DNSSEC)) != 0U)
+			n = res_nopt(res, n, buf, MAXPACKET, anslen);
 		if (n <= 0) {
 #ifdef DEBUG
-			if (_res.options & RES_DEBUG)
+			if (res->options & RES_DEBUG)
 				printf(";; res_query: mkquery failed\n");
 #endif
 			free(buf);
-			h_errno = NO_RECOVERY;
+			RES_SET_H_ERRNO(res, NO_RECOVERY);
 			return (n);
 		}
-		n = lookupd_res_send(buf, n, answer, anslen);
-#if 0
+		n = res_nsend(res, buf, n, answer, anslen);
 		if (n < 0) {
+#ifdef RES_F_EDNS0ERR
+			/*
+			 * if the query choked with EDNS0, retry
+			 * without EDNS0
+			 */
+			if ((res->options & (RES_USE_EDNS0|RES_USE_DNSSEC))
+			    != 0U &&
+			    ((oflags ^ res->_flags) & RES_F_EDNS0ERR) != 0) {
+				res->_flags |= RES_F_EDNS0ERR;
+				if (res->options & RES_DEBUG)
+					printf(";; res_nquery: retry without EDNS0\n");
+				goto again;
+			}
+#endif
+			rcode = hp->rcode;	/* record most recent error */
 #ifdef DEBUG
-			if (_res.options & RES_DEBUG)
+			if (res->options & RES_DEBUG)
 				printf(";; res_query: send error\n");
 #endif
-			free(buf);
-			h_errno = TRY_AGAIN;
-			return (n);
+			continue;
 		}
-#endif
 
-		if (n < 0 || n > anslen)
-			hp->rcode = FORMERR;	/* XXX not very informative */
+		if (n > anslen)
+			hp->rcode = FORMERR; /* XXX not very informative */
 		if (hp->rcode != NOERROR || ntohs(hp->ancount) == 0) {
 			rcode = hp->rcode;	/* record most recent error */
 #ifdef DEBUG
-			if (_res.options & RES_DEBUG)
+			if (res->options & RES_DEBUG)
 				printf(";; rcode = %u, ancount=%u\n", hp->rcode,
-					ntohs(hp->ancount));
+				    ntohs(hp->ancount));
 #endif
 			continue;
 		}
+
 		ancount += ntohs(hp->ancount);
 
 		t->n = n;
@@ -1929,19 +793,19 @@
 	if (ancount == 0) {
 		switch (rcode) {
 		case NXDOMAIN:
-			h_errno = HOST_NOT_FOUND;
+			RES_SET_H_ERRNO(res, HOST_NOT_FOUND);
 			break;
 		case SERVFAIL:
-			h_errno = TRY_AGAIN;
+			RES_SET_H_ERRNO(res, TRY_AGAIN);
 			break;
 		case NOERROR:
-			h_errno = NO_DATA;
+			RES_SET_H_ERRNO(res, NO_DATA);
 			break;
 		case FORMERR:
 		case NOTIMP:
 		case REFUSED:
 		default:
-			h_errno = NO_RECOVERY;
+			RES_SET_H_ERRNO(res, NO_RECOVERY);
 			break;
 		}
 		return (-1);
@@ -1950,25 +814,25 @@
 }
 
 /*
- * Formulate a normal query, send, and retrieve answer in supplied buffer. Return the size of the response on success, -1 on error. If enabled, implement search rules until answer or unrecoverable failure is detected.  Error code, if any, is left in h_errno.
+ * Formulate a normal query, send, and retrieve answer in supplied buffer.
+ * Return the size of the response on success, -1 on error.
+ * If enabled, implement search rules until answer or unrecoverable failure
+ * is detected.  Error code, if any, is left in h_errno.
  */
 static int
-res_searchN(name, target)
-	const char *name;	/* domain name */
-	struct res_target *target;
+res_searchN(const char *name, struct res_target *target, res_state res)
 {
-	const char *cp, *const *domain;
-	HEADER *hp = (HEADER *) (void *)target->answer;	/* XXX */
+	const char *cp, * const *domain;
+	HEADER *hp = (HEADER *)(void *)target->answer;	/*XXX*/
 	u_int dots;
 	int trailing_dot, ret, saved_herrno;
-	int got_nodata = 0, got_servfail = 0, tried_as_is = 0;
+	int got_nodata = 0, got_servfail = 0, root_on_list = 0;
+	int tried_as_is = 0;
+	int searched = 0;
+	char abuf[MAXDNAME];
 
-	if ((_res.options & RES_INIT) == 0 && lookupd_res_init() == -1) {
-		h_errno = NETDB_INTERNAL;
-		return (-1);
-	}
 	errno = 0;
-	h_errno = HOST_NOT_FOUND;	/* default, if we never query */
+	RES_SET_H_ERRNO(res, HOST_NOT_FOUND); /* default, if we never query */
 	dots = 0;
 	for (cp = name; *cp; cp++)
 		dots += (*cp == '.');
@@ -1979,43 +843,84 @@
 	/*
 	 * if there aren't any dots, it could be a user-level alias
 	 */
-	if (!dots && (cp = __hostalias(name)) != NULL)
-		return (res_queryN(cp, target));
+	if (!dots &&
+	    (cp = res_hostalias(res, name, abuf, sizeof(abuf))) != NULL)
+		return (res_queryN(cp, target, res));
 
 	/*
-	 * If there are dots in the name already, let's just give it a try 'as is'.  The threshold can be set with the "ndots" option.
+	 * If there are enough dots in the name, let's just give it a
+	 * try 'as is'. The threshold can be set with the "ndots" option.
+	 * Also, query 'as is', if there is a trailing dot in the name.
 	 */
 	saved_herrno = -1;
-	if (dots >= _res.ndots) {
-		ret = res_querydomainN(name, NULL, target);
-		if (ret > 0)
+	if (dots >= res->ndots || trailing_dot) {
+		ret = res_querydomainN(name, NULL, target, res);
+		if (ret > 0 || trailing_dot)
 			return (ret);
-		saved_herrno = h_errno;
+		if (errno == ECONNREFUSED) {
+			RES_SET_H_ERRNO(res, TRY_AGAIN);
+			return (-1);
+		}
+		switch (H_ERRNO(res)) {
+		case NO_DATA:
+		case HOST_NOT_FOUND:
+			break;
+		case TRY_AGAIN:
+			if (hp->rcode == SERVFAIL)
+				break;
+			/* FALLTHROUGH */
+		default:
+			return (-1);
+		}
+		saved_herrno = H_ERRNO(res);
 		tried_as_is++;
 	}
+
 	/*
-	 * We do at least one level of search if - there is no dot and RES_DEFNAME is set, or - there is at least one dot, there is no trailing dot, and RES_DNSRCH is set.
+	 * We do at least one level of search if
+	 *	- there is no dot and RES_DEFNAME is set, or
+	 *	- there is at least one dot, there is no trailing dot,
+	 *	  and RES_DNSRCH is set.
 	 */
-	if ((!dots && (_res.options & RES_DEFNAMES)) ||
-		(dots && !trailing_dot && (_res.options & RES_DNSRCH))) {
+	if ((!dots && (res->options & RES_DEFNAMES)) ||
+	    (dots && !trailing_dot && (res->options & RES_DNSRCH))) {
 		int done = 0;
 
-		for (domain = (const char *const *)_res.dnsrch;
-			*domain && !done;
-			domain++) {
+		for (domain = (const char * const *)res->dnsrch;
+		   *domain && !done;
+		   domain++) {
+			searched = 1;
+
+			if (domain[0][0] == '\0' ||
+			    (domain[0][0] == '.' && domain[0][1] == '\0'))
+				root_on_list++;
+
+			if (root_on_list && tried_as_is)
+				continue;
 
-			ret = res_querydomainN(name, *domain, target);
+			ret = res_querydomainN(name, *domain, target, res);
 			if (ret > 0)
 				return (ret);
 
 			/*
-			 * If no server present, give up. If name isn't found in this domain, keep trying higher domains in the search list (if that's enabled). On a NO_DATA error, keep trying, otherwise a wildcard entry of another type could keep us from finding this entry higher in the domain. If we get some other error (negative answer or server failure), then stop searching up, but try the input name below in case it's fully-qualified.
+			 * If no server present, give up.
+			 * If name isn't found in this domain,
+			 * keep trying higher domains in the search list
+			 * (if that's enabled).
+			 * On a NO_DATA error, keep trying, otherwise
+			 * a wildcard entry of another type could keep us
+			 * from finding this entry higher in the domain.
+			 * If we get some other error (negative answer or
+			 * server failure), then stop searching up,
+			 * but try the input name below in case it's
+			 * fully-qualified.
 			 */
 			if (errno == ECONNREFUSED) {
-				h_errno = TRY_AGAIN;
+				RES_SET_H_ERRNO(res, TRY_AGAIN);
 				return (-1);
 			}
-			switch (h_errno) {
+
+			switch (H_ERRNO(res)) {
 			case NO_DATA:
 				got_nodata++;
 				/* FALLTHROUGH */
@@ -2023,9 +928,9 @@
 				/* keep trying */
 				break;
 			case TRY_AGAIN:
+				got_servfail++;
 				if (hp->rcode == SERVFAIL) {
 					/* try next search element, if any */
-					got_servfail++;
 					break;
 				}
 				/* FALLTHROUGH */
@@ -2034,60 +939,80 @@
 				done++;
 			}
 			/*
-			 * if we got here for some reason other than DNSRCH, we only wanted one iteration of the loop, so stop.
+			 * if we got here for some reason other than DNSRCH,
+			 * we only wanted one iteration of the loop, so stop.
 			 */
-			if (!(_res.options & RES_DNSRCH))
-				done++;
+			if (!(res->options & RES_DNSRCH))
+			        done++;
 		}
 	}
+
+	switch (H_ERRNO(res)) {
+	case NO_DATA:
+	case HOST_NOT_FOUND:
+		break;
+	case TRY_AGAIN:
+		if (hp->rcode == SERVFAIL)
+			break;
+		/* FALLTHROUGH */
+	default:
+		goto giveup;
+	}
+
 	/*
-	 * if we have not already tried the name "as is", do that now. note that we do this regardless of how many dots were in the name or whether it ends with a dot.
+	 * If the query has not already been tried as is then try it
+	 * unless RES_NOTLDQUERY is set and there were no dots.
 	 */
-	if (!tried_as_is && (dots || !(_res.options & RES_NOTLDQUERY))) {
-		ret = res_querydomainN(name, NULL, target);
+	if ((dots || !searched || !(res->options & RES_NOTLDQUERY)) &&
+	    !(tried_as_is || root_on_list)) {
+		ret = res_querydomainN(name, NULL, target, res);
 		if (ret > 0)
 			return (ret);
 	}
+
 	/*
-	 * if we got here, we didn't satisfy the search. if we did an initial full query, return that query's h_errno (note that we wouldn't be here if that query had succeeded). else if we ever got a nodata, send that back as the reason. else send back meaningless h_errno, that being the one from the last DNSRCH we did.
+	 * if we got here, we didn't satisfy the search.
+	 * if we did an initial full query, return that query's h_errno
+	 * (note that we wouldn't be here if that query had succeeded).
+	 * else if we ever got a nodata, send that back as the reason.
+	 * else send back meaningless h_errno, that being the one from
+	 * the last DNSRCH we did.
 	 */
+giveup:
 	if (saved_herrno != -1)
-		h_errno = saved_herrno;
+		RES_SET_H_ERRNO(res, saved_herrno);
 	else if (got_nodata)
-		h_errno = NO_DATA;
+		RES_SET_H_ERRNO(res, NO_DATA);
 	else if (got_servfail)
-		h_errno = TRY_AGAIN;
+		RES_SET_H_ERRNO(res, TRY_AGAIN);
 	return (-1);
 }
 
 /*
- * Perform a call on res_query on the concatenation of name and domain, removing a trailing dot from name if domain is NULL.
+ * Perform a call on res_query on the concatenation of name and domain,
+ * removing a trailing dot from name if domain is NULL.
  */
 static int
-res_querydomainN(name, domain, target)
-	const char *name, *domain;
-	struct res_target *target;
+res_querydomainN(const char *name, const char *domain,
+    struct res_target *target, res_state res)
 {
 	char nbuf[MAXDNAME];
 	const char *longname = nbuf;
 	size_t n, d;
 
-	if ((_res.options & RES_INIT) == 0 && lookupd_res_init() == -1) {
-		h_errno = NETDB_INTERNAL;
-		return (-1);
-	}
 #ifdef DEBUG
-	if (_res.options & RES_DEBUG)
+	if (res->options & RES_DEBUG)
 		printf(";; res_querydomain(%s, %s)\n",
-			name, domain ? domain : "<Nil>");
+			name, domain?domain:"<Nil>");
 #endif
 	if (domain == NULL) {
 		/*
-		 * Check for trailing '.'; copy without '.' if present.
+		 * Check for trailing '.';
+		 * copy without '.' if present.
 		 */
 		n = strlen(name);
 		if (n >= MAXDNAME) {
-			h_errno = NO_RECOVERY;
+			RES_SET_H_ERRNO(res, NO_RECOVERY);
 			return (-1);
 		}
 		if (n > 0 && name[--n] == '.') {
@@ -2099,10 +1024,10 @@
 		n = strlen(name);
 		d = strlen(domain);
 		if (n + d + 1 >= MAXDNAME) {
-			h_errno = NO_RECOVERY;
+			RES_SET_H_ERRNO(res, NO_RECOVERY);
 			return (-1);
 		}
 		snprintf(nbuf, sizeof(nbuf), "%s.%s", name, domain);
 	}
-	return (res_queryN(longname, target));
+	return (res_queryN(longname, target, res));
 }
