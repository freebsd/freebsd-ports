# $FreeBSD$

PORTNAME=	dual-dhclient-daemon
PORTVERSION=	0.1
CATEGORIES=	net

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Spawns dhclients for a dual-stack network

LICENSE=	PD

RUN_DEPENDS=	${LOCALBASE}/sbin/dhclient:net/isc-dhcp44-client

USE_GITHUB=	yes
GH_ACCOUNT=	cperciva
GH_PROJECT=	dual-dhclient

PLIST_FILES=	sbin/dual-dhclient

CONFLICTS_INSTALL=	dual-dhclient

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dual-dhclient ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
