# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	deviceAdvDetail
PORTVERSION=	2.7.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/epuzanov/${ZPACKPREFIX}${PORTNAME}/tarball/deviceadvdetail-2.7/
DISTNAME=	epuzanov-${ZPACKPREFIX}${PORTNAME}-deviceadvdetail-2.7-0-g4cc7c48

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides additional hardware details for Zenoss

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/epuzanov-${ZPACKPREFIX}${PORTNAME}-cfbd596

ZPACK=	${ZPACKPREFIX}${PORTNAME}-2.7-${PYTHON_VERSION:S/thon//}.egg
ZPACKPREFIX=	ZenPacks.community.

NO_STAGE=	yes
.include <bsd.port.mk>
