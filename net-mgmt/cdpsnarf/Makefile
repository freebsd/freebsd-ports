# $FreeBSD$

PORTNAME=	cdpsnarf
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt
MASTER_SITES=	GH

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Tool to extract information from CDP packets

LICENSE=	GPLv2

LIB_DEPENDS=	libpcap.so:net/libpcap

USE_GITHUB=	yes
GH_ACCOUNT=	Zapotek

post-patch:
	${REINPLACE_CMD} -e 's|gcc|cc|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
