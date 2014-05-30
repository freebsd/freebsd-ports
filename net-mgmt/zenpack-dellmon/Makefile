# Created by: Zenoss <zenoss@experts-exchange.com>
# $FreeBSD$

PORTNAME=	DellMon
PORTVERSION=	2.4

CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/epuzanov/${ZPACKPREFIX}${PORTNAME}/tarball/dellmon-2.4/
DISTNAME=	epuzanov-${ZPACKPREFIX}${PORTNAME}-dellmon-2.4-0-g9697659

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides additional monitoring options for Dell machines

PLIST_FILES=	zenoss/ZenPack/${ZPACK}
PLIST_DIRS=	zenoss/ZenPack
USES=		zenoss

ZPACKGROUP=	community
WRKSRC=		${WRKDIR}/epuzanov-${ZPACKPREFIX}${PORTNAME}-a4ae347
ZPACKPREFIX=    ZenPacks.community.

NO_STAGE=	yes
.include <bsd.port.mk>
