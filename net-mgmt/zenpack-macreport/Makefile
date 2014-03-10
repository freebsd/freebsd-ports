# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	MACReport
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/zipball/master/
DISTNAME=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Lists MAC address and the Device and Interface associated info

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

USES=		zip
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=	b345f53

ZPACKPREFIX=	ZenPacks.sodonnell.

NO_STAGE=	yes
.include <bsd.port.mk>
