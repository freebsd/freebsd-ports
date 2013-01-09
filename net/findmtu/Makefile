# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	findmtu
PORTVERSION=	0.9
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.dia.uniroma3.it/~compunet/tunneldiscovery/findmtu/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	A tool for performing IPv6 path MTU discovery on *NIX

SUB_FILES=	findmtu

do-configure:
	${LN} -s ${WRKSRC}/Makefile.rawsocket ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/findmtu ${PREFIX}/bin/findmtu
	${INSTALL_PROGRAM} ${WRKSRC}/findmtu ${PREFIX}/bin/findmtu.real
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.freebsd ${DOCSDIR}
.endif

.include <bsd.port.mk>
