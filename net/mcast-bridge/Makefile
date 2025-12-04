PORTNAME=	mcast-bridge
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	net

MAINTAINER=	dennypage@me.com
COMMENT=	Multicast Bridge
WWW=		https://github.com/dennypage/mcast-bridge

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	dennypage

USE_RC_SUBR=	mcast_bridge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/mcast-sr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
