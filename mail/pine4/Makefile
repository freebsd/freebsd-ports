# New ports collection makefile for:	pine
# Date created:		09 July 1998
# Whom:			Adrian Penisoara <ady@freebsd.ady.ro>
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.61
CATEGORIES=	mail news ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		http://mirror.sit.wisc.edu/pub/net/mail/pine/ \
		ftp://sunsite.icm.edu.pl/pub/unix/mail/pine/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/ \
		ftp://ftp.ut.ee/pub/unix/mail/pine/ \
		ftp://gd.tuwien.ac.at/infosys/mail/pine/
DISTNAME=	pine${PORTVERSION}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	PINE(tm) -- a Program for Internet News & Email

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

# Define "WITH_LDAP" to include ldap support.
#
.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
LDAP_PREFIX?=	${LOCALBASE}
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

.if defined(WITH_IPV6)
EXTRA_OPTS+=	IP=6
.endif

MAN1=		pine.1 pico.1 pilot.1 rpdump.1 rpload.1

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} pkg-install
.endif

post-patch:
.for f in build buildcyg
	@${CP} ${WRKSRC}/${f} ${WRKSRC}/${f}.presed
	@${SED} -e 's:CC=cc:CC=${CC}:g' ${WRKSRC}/${f}.presed > ${WRKSRC}/${f}
.endfor
	@for i in ${WRKSRC}/README ${WRKSRC}/doc/pine.1 \
		${WRKSRC}/doc/tech-notes.txt ${WRKSRC}/doc/tech-notes/*.html \
		${WRKSRC}/pico/osdep/os-bsf.h \
		${WRKSRC}/pine/init.c ${WRKSRC}/pine/mailcap.c \
		${WRKSRC}/pine/osdep/os-bsf.h ${WRKSRC}/pine/pine.hlp ; do \
		${CP} $$i $$i.presed ; \
		${SED}	-e "s:/usr/local/etc/:${PREFIX}/etc/:g" \
			-e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
			-e "s:@@PREFIX@@:${PREFIX}:g" \
			-e "s:/usr/local/pine.conf:${PREFIX}/etc/pine.conf:g" \
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
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${manpage} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR} \
		${DOCSDIR}/tech-notes
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html ${DOCSDIR}/tech-notes
.endif

post-install:
	${PREFIX}/bin/pine -P ${PREFIX}/etc/pine.conf -conf >${WRKSRC}/pine.conf
	${INSTALL_DATA} ${WRKSRC}/pine.conf ${PREFIX}/etc/pine.conf

	@${CAT} pkg-message

.include <bsd.port.mk>
