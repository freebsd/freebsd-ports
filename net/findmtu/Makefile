# New ports collection makefile for:	findmtu
# Date created:		13 July 2004
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	findmtu
PORTVERSION=	0.9
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.dia.uniroma3.it/~compunet/tunneldiscovery/findmtu/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A tool for performing IPv6 path MTU discovery on *NIX

do-configure:
	${LN} -s ${WRKSRC}/Makefile.rawsocket ${WRKSRC}/Makefile

post-build:
	${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/findmtu.sh > ${WRKDIR}/findmtu

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/findmtu ${PREFIX}/bin/findmtu
	${INSTALL_PROGRAM} ${WRKSRC}/findmtu ${PREFIX}/bin/findmtu.real
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.freebsd ${DOCSDIR}
.endif

.include <bsd.port.mk>
