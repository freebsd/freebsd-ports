PORTNAME=	mdns-bridge
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	dennypage@me.com
COMMENT=	Multicast DNS Bridge
WWW=		https://github.com/dennypage/mdns-bridge

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	dennypage

USE_RC_SUBR=	mdns_bridge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
