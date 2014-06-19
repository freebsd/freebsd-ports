# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	InterfaceGraphs
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/
DISTNAME=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides a link that graphs all network interfaces for a device

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKGROUP=	community
ZPACKPREFIX=	ZenPacks.community.
WRKSRC=		${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=		7ed2d7d

NO_STAGE=	yes
.include <bsd.port.mk>
