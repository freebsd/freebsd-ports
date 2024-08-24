PORTNAME=	udpbroadcastrelay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	net

MAINTAINER=	m.muenz@gmail.com
COMMENT=	UDP multicast/unicast relayer
WWW=		https://github.com/marjohn56/udpbroadcastrelay

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	marjohn56
GH_TAGNAME=	07d7479

PLIST_FILES=	sbin/udpbroadcastrelay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udpbroadcastrelay ${STAGEDIR}${PREFIX}/sbin/udpbroadcastrelay

.include <bsd.port.mk>
