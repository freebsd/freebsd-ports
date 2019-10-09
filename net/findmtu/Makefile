# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	findmtu
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://www.dia.uniroma3.it/~compunet/tunneldiscovery/findmtu/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Tool for performing IPv6 path MTU discovery on *NIX

OPTIONS_DEFINE=	DOCS

SUB_FILES=	findmtu

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile.rawsocket

do-configure:
	${LN} -s ${WRKSRC}/Makefile.rawsocket ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/findmtu ${STAGEDIR}${PREFIX}/bin/findmtu
	${INSTALL_PROGRAM} ${WRKSRC}/findmtu ${STAGEDIR}${PREFIX}/bin/findmtu.real

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.freebsd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
