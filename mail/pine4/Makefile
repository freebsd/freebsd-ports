# New ports collection makefile for:	pine
# Date created:		09 July 1998
# Whom:			Adrian Penisoara <ady@freebsd.ady.ro>
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.53
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	DougB@FreeBSD.org

# Define "WITH_LDAP" to include ldap support.
# If the ldap port is installed somewhere other than /usr/local, define
# LDAP_PREFIX as well.
#
.if defined(WITH_LDAP)
LDAP_PREFIX?=	${LOCALBASE}
BUILD_DEPENDS+=	${LDAP_PREFIX}/lib/libldap.a:${PORTSDIR}/net/openldap
.endif

.if defined(WITHOUT_SSL)
MAKE_ARGS+=	SSLTYPE=none
.else
USE_OPENSSL=	yes
EXTRA_OPTS=	SSLINCLUDE=${OPENSSLINC} SSLLIB=${OPENSSLLIB}
.if defined(WITH_SSL_AND_PLAINTEXT)
EXTRA_OPTS+=	SSLTYPE=unix
.else
EXTRA_OPTS+=	SSLTYPE=unix.nopwd
.endif
.endif

MAN1=		pine.1 pico.1 pilot.1 rpdump.1 rpload.1

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} pkg-install
.endif

post-patch:
.for file in doc/pine.1 pine/init.c pine/pine.hlp pine/mailcap.c \
	pine/osdep/os-bsf.h
	@${CP} ${WRKSRC}/${file} ${WRKSRC}/${file}.presed
	@${SED} -e "s:@@PREFIX@@:${PREFIX}:g" ${WRKSRC}/${file}.presed > \
		${WRKSRC}/${file}
.endfor
	@for i in ${WRKSRC}/doc/tech-notes.txt \
		${WRKSRC}/doc/tech-notes/*.html ; do \
		${CP} $$i $$i.presed ; \
		${SED} -e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
			$$i.presed > $$i ; \
	done
.if defined(WITH_LDAP)
	${MKDIR} ${WRKSRC}/ldap
	${LN} -sf ${LDAP_PREFIX}/include ${WRKSRC}/ldap/include
	${LN} -sf ${LDAP_PREFIX}/lib ${WRKSRC}/ldap/libraries
.endif

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf ${EXTRA_OPTS})

do-install:
.for program in ${MAN1}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${program:R} ${PREFIX}/bin
.endfor
.for script in pgpdecode pgpencrypt pgpsign
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/${script} > \
		${WRKSRC}/bin/${script}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${PREFIX}/bin
.endfor
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/dot.pinerc.pgp.sample \
		> ${WRKSRC}/dot.pinerc.pgp.sample
	${INSTALL_DATA} ${WRKSRC}/dot.pinerc.pgp.sample \
		${PREFIX}/etc/dot.pinerc.pgp.sample
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${manpage} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR} \
		${DOCSDIR}/tech-notes
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html ${DOCSDIR}/tech-notes
.endif

post-install:
	${PREFIX}/bin/pine -P ${PREFIX}/etc/pine.conf -conf >${WRKSRC}/pine.conf
	${INSTALL_DATA} ${WRKSRC}/pine.conf ${PREFIX}/etc/pine.conf

.include <bsd.port.mk>
