# New ports collection makefile for:	ipsvd
# Date created:		01 Apr 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	ipsvd
PORTVERSION=	0.11.0
CATEGORIES=	net
MASTER_SITES=	http://smarden.org/ipsvd/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Internet protocol service daemons

WRKSRC=		${WRKDIR}/net/${DISTNAME}
ALL_TARGET=	default

MAN5=		ipsvd-instruct.5
MAN7=		ipsvd.7
MAN8=		ipsvd-cdb.8 sslio.8 tcpsvd.8 udpsvd.8
DOCS=		package/CHANGES package/COPYING package/README doc/*.html

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	@${ECHO_CMD} "${LOCALBASE}/include/libdjbdns" \
		> ${WRKSRC}/src/conf-djbdnsinc
	@${ECHO_CMD} "${LOCALBASE}/lib" > ${WRKSRC}/src/conf-djbdnslib

do-build:
	cd ${WRKSRC} && package/compile && package/check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/sbin
.for n in 5 7 8
	${INSTALL_MAN} ${WRKSRC}/man/*.${n} ${MANPREFIX}/man/man${n}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
