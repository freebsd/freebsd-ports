# $FreeBSD$

PORTNAME=	udpbroadcastrelay
DISTVERSIONPREFIX=v
DISTVERSION=	0.3-beta
CATEGORIES=	net

MAINTAINER=	m.muenz@gmail.com
COMMENT=	UDP multicast/unicast relayer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	marjohn56

PLIST_FILES=	sbin/udpbroadcastrelay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udpbroadcastrelay ${STAGEDIR}${PREFIX}/sbin/udpbroadcastrelay

.include <bsd.port.mk>
